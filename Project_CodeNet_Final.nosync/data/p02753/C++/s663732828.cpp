#include <iostream>
#include<string>
using namespace std;

int main()
{

   string a;
   cin>>a;
   int m,c=0,d=0;
   m=a.length();
   for(int i=0;i<m;i++)
   {
       if(a[i]=='A')
       {
           c++;
       }
       else if(a[i]=='B')
       {
           d++;
       }
   }
   if(c!=0&&d!=0)
   {
       cout<<"Yes";
   }
   else cout<<"No";
}
