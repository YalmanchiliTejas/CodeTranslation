#include <stdlib.h> 
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std; 

int main()
{
   string s;

   cin>>s;

   if(s.substr(0,1) != s.substr(1,1) || s.substr(0,1) != s.substr(2,1) ) cout<<"Yes";
   else cout<<"No";

}

