#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a,b,c;
   while(cin>>a>>b>>c)
   {
       int sum=0;
       sum=b*10+c;
      // cout<<"sum="<<sum<<endl;
       sum=a*100+sum;
      // cout<<sum<<endl;
       if(sum%4==0)
       {
           cout<<"YES"<<endl;
       }
       else
       {
           cout<<"NO"<<endl;
       }

   }


   return 0;
}
