#include <iostream> 
#include <cassert> 
#include <vector> 
#include <cmath> 
#include <ctime> 
#include <cstdlib> 
#include <fstream> 
#include <string> 
#include <sstream> 
#include <iterator> 
#include <map> 
#include <algorithm> 
#include <memory> 
#include <iomanip> 
#include <limits> 
#include <typeinfo> 
#include <queue> 

//------------------------

#include <stdio.h> 
#include <string.h> 


using namespace std;

int main()
{
   int X,Y,Z;
   int space;

   cin >> X >> Y >> Z;

   space = (int)(X-Z)/(Y+Z);

   cout << space << endl;

   return 0;

}