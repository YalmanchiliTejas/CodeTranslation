#include<bits/stdc++.h>
using namespace std;
#define int long long int 
int32_t main()
{
   int x,y;
   cin>>x>>y;
   vector<string> s;
   for(int i=0;i<x;i++)
   {
       string t;
       cin>>t;
       if(count(t.begin(),t.end(),'.')!=t.size())
       s.push_back(t);
   }
     char a[s.size()][s[0].size()];
     int allow[s[0].size()];
     for(int i=0;i<=s[0].size();i++)
     allow[i]=0;

     for(int i=0;i<s.size();i++)
     for(int j=0;j<s[0].size();j++)
     a[i][j]=s[i][j];

   
     for(int j=0;j<s[0].size();j++)
      for(int i=0;i<s.size();i++)
     if(a[i][j]=='.')allow[j]++;
    //  for(auto i:allow)
    //  cout<<i<<" ";
    //  cout<<endl;
     for(int i=0;i<s.size();i++){
     for(int j=0;j<s[0].size();j++)
     {
         if(allow[j]==s.size())continue;
         cout<<a[i][j];
     }
     cout<<endl;
     }

}