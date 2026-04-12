#include<bits/stdc++.h>
 using namespace std;

#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long
#define endl '\n'
#define eps  1e-9
const double pi=acos(-1);

const int mod=1e9+7;
//_______________________

int h[22];

int32_t main()
{ 
  io;
  
  
  int cnt=0,n;
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>h[i];

  for(int i=1;i<=n;i++)
  {
    bool ok=true;
    for(int j=0;j<i;j++)
    {
      if(h[j]>h[i])
        ok=false;
    }
    if(ok)
      cnt++;
  }

  cout<<cnt;
  
 return 0;
}