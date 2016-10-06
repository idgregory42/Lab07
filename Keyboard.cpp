#include "Text.h"
using CSC2110::String;
#include "Keyboard.h"
using CSC2110::Keyboard;
#include <iostream>

Keyboard::Keyboard()
{
}

Keyboard::~Keyboard()
{
}

Keyboard* Keyboard::getKeyboard()
{
   static Keyboard keyboard;  //initialized when method is called the first time
   return &keyboard;  //won't go out of scope as keyboard is static
}

int Keyboard::readInt(string prompt)
{
   cout << prompt;
   int val = 0;
   cin >> val;
   return val;
}

int Keyboard::getValidatedInt(string prompt, int min, int max)
{
  
   int validated = 0;
   String* v = new String("\a\n**Invalid Input**\n");
   do
   {
      validated = readInt(prompt);
	   if(validated < min || validated > max)
	   {
			v->displayString();
	   }
      
   }while(validated < min || validated > max);

   delete v;
   return validated;
}

double Keyboard::readDouble(string prompt)
{
   cout << prompt;
   double val = 0.0;
   cin >> val;
   return val;
}

double Keyboard::getValidatedDouble(string prompt, double min, double max)
{
   double validated = 0.0;
   String* v = new String("\a\n**Invalid Input**\n");
   do
   {
      validated = readDouble(prompt);
	   if(validated < min || validated > max)
	   {
			v->displayString();
	   }
      
   }while(validated < min || validated > max);
   
   delete v;
   return validated;
}

String* Keyboard::readString(string prompt)
{
   cout << prompt;
   string text;
   getline(cin, text);

   String* str = new String(text.c_str());
   return str;
}
