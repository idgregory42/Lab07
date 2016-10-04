#include "RombergIntegration.h"
#include "RecursiveIntegration.h"
#include "QueueLinked.h"
#include "CSC2110/Double.h"
using CSC2110::Double;
#include <iostream>
using namespace std;
#include <math.h>

//a is the lower limit and b is the upper limit
double RombergIntegration::accurateRomberg(MultiVarFunction* f, double a, double b, int level)
{
   Double* db;  //use this variable to place and retrieve values on the queue
 
   QueueLinked<Double>* q1 = new QueueLinked<Double>();
   QueueLinked<Double>* q2 = new QueueLinked<Double>();


   int counter = 0;
   int n = 1;  //current number of intervals
   cout << "\n**Level: " << level << endl;
   while (counter <= level )
   {
      //DO THIS
      //obtain the required number of trapezoid evaluations depending on the number of levels requested
      //put all of the level 0 results on the q1
	  double _dis = RecursiveIntegration::romberg(f, a, b, n);
	  db = new Double(_dis);
	  q1->enqueue(db);
      n = 2*n;  //double the number of intervals
      counter++;
   }

	
   //q1 now has all of the level 0 integration results

   double factor;  //use this to compute the current Romberg Factor (4^k stuff)
   int power = 1;  //k, used to compute the Romberg Factor

   //if level 0 has been requested, the loop will not execute
   //the total number of executions of the loop is ??

   //DO THIS
   int iterations = counter - 1;         //can be precomputed
   cout <<"\n** 69" << endl;
   int sz = q1->size();
   cout << "\n** Size:"<<sz << endl;
   cout << "\n\a" << endl;
   while(iterations > 0)
   {
      //DO THIS
      //use the algorithm described in the lab to improve the accuracy of your level 0 results

		
		while(q1->size() != 1)
		{
			Double* iL_D = q1->dequeue();
			double iL = iL_D->getValue();
			double iM = q1->peek()->getValue();
			factor = pow(4, power);
			double calc = ((factor*iM)-iL)/(factor - 1);
			
			Double* db2 = new Double(calc);
			q2->enqueue(db2);			
		}
		
		int num = q2->size();
		q1->dequeueAll();
		for (int i = 0; i < num; i++)
		{
			q1->enqueue(q2->dequeue());
		}

		power++;
/*		
		q1->dequeueAll();
		for (int i = 0; i < q2->size(); i++)
		{
			q1->enqueue(q2->dequeue());
		}
*/	


		
		iterations--;
		
   }

   //obtain the final answer
   db = q1->dequeue();

   double result = db->getValue(); 

   delete db;
   delete q1;
   delete q2;

   return result;
}
