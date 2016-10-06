#include "Problem22_1.h"
#include "RombergIntegration.h"
#include "RecursiveIntegration.h"
#include "CSC2110/Keywait.h"
using CSC2110::Keywait;
#include "CSC2110/Valtostr.h"
using CSC2110::Valtostr;
#include "CSC2110/Text.h"
using CSC2110::String;

#include <math.h>

Problem22_1::Problem22_1() 
{}

Problem22_1::~Problem22_1()
{}

//the function evaluation depends on the current values for the parameters
double Problem22_1::evaluate(double* xy)
{
   double x = xy[0];
   double result = 2*x;
   result += 3/x;
   result *= result;
   return result;
}

double Problem22_1::integrate(int level)
{
   return RombergIntegration::accurateRomberg(this, lower, upper, level);
}

//insert a set limits method to set the upper and lower limits
void Problem22_1::setLowerLimit(double a)
{
   lower = a;
}

void Problem22_1::setUpperLimit(double b)
{
   upper = b;
}

int main()
{
   Problem22_1* p = new Problem22_1();  //mean = 10.5, variance = 5.7
 
   //lower limits
   p->setLowerLimit(1.0);
   p->setUpperLimit(2.0);
   
   String* res;
   String* num_res;
   String* end_line = new String("\n");
   Valtostr* d2a = new Valtostr();
   
   double result = 0.0;

   result = p->integrate(0);
   res = new String("The area under the curve using accurate Romberg level 0: ");
   res->displayString();
   num_res = new String(d2a->d_to_c(result));
   num_res->displayString();
   end_line->displayString();
   
   result = p->integrate(1);
   res = new String("The area under the curve using accurate Romberg level 1: ");
   res->displayString();
   num_res = new String(d2a->d_to_c(result));
   num_res->displayString();
   end_line->displayString();   
   
   result = p->integrate(2);   
   res = new String("The area under the curve using accurate Romberg level 2: ");
   res->displayString();
   num_res = new String(d2a->d_to_c(result));
   num_res->displayString();
   end_line->displayString();   
   
   
   result = p->integrate(3);  
   res = new String("The area under the curve using accurate Romberg level 3: ");
   res->displayString();
   num_res = new String(d2a->d_to_c(result));
   num_res->displayString();
   end_line->displayString();  
   
   Keywait* kw = new Keywait();
   kw->waitForKey();
   

   delete res;
   delete num_res;
   delete end_line;
   delete d2a;
   delete p;
   return 0;
}
