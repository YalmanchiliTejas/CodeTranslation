#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,k;
   cin>>n;
   char a[n];
   cin>>a;
   cin>>k;
   char x=a[k-1];
   for(int i=0;i<n;i++)
   {
       if(a[i]!=x)
        a[i]='*';
   }
   cout<<a<<endl;
   return 0;
}
