#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   ll n,k;
   string s;
   cin>>n>>s>>k;
   for(ll i=0;i<n;i++)
   {
       if(s[i]!=s[k-1])
       s[i]='*';
   }
   cout<<s;
}