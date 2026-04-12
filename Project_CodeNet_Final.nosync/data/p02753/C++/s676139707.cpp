#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define pf push_front
#define mod 1000000007
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


int main()
{
   string s;
   cin>>s;
   ll flag=0;
   ll n=s.length(),i;
   for(i=0;i<n-1;i++)
   {
       if((s[i]=='A' && s[i+1]=='B') || (s[i]=='B' && s[i+1]=='A') )
       {
           flag=1;
       }
   }
   if(flag)
   {
       cout<<"Yes"<<endl;
   }
   else
   {
       cout<<"No"<<endl;
   }
}
