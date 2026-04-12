#include<bits/stdc++.h>
 using namespace std;

#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long
#define endl '\n'
#define eps  1e-9
const double pi=acos(-1);
const int mod=1e9+7;
//_______________________



int32_t main()
{ 
  io;
 
 
  int n,k;
  string s;
  cin>>n>>s>>k;

  char c=s[k-1];

  for(int i=0;i<n;i++)
  {
    if(s[i]!=c)
      s[i]='*';
  }
  
  cout<<s;
  
 return 0;
}