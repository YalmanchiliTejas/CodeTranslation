#include <iostream>
using namespace std;
int main(void){
    // Your code here!
   string s;
   cin>>s;
   int a=0,b=0;
   for(int i=0;i<3;i++)
   {
       if(s[i]=='A')
       a++;
       else
       b++;
   }
   if(a==0 || b==0)
   cout<<"No";
   else
   cout<<"Yes";
   }
