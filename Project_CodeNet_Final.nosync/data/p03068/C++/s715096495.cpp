#include <bits/stdc++.h>
using namespace std;


int main()
{
   int n, k;
   string s="";
   cin>>n;
   cin>>s;
   cin>>k;

   char ch = s[k-1];
   for(int i=0;i<n;i++)
   {
     if(s[i]==ch)
     cout<<s[i];
     else if(s[i]!=ch)
     cout<<"*";

   }
   cout<<endl;
   return 0;
   
}
