#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n;
  ll x;cin>>n>>x;
  vector<ll> meat(n+1,0);
  vector<ll> pan(n+1,0);
  meat[0]=1;
  int i;
  for(i=1;i<=n;i++)
  {
    meat[i]=meat[i-1]*2+1;
    pan[i]=pan[i-1]*2+2;
  }
  ll right=meat[n]+pan[n];
  ll left=1;
  ll mid;
  ll ans=0;
  int nlev=n;
  while(nlev>0)
  {
    mid=(left+right)/2;
    if(x==left)break;
    else if(x==right)
    {
      ans+=meat[nlev];
      break;
    }
    else if(x<mid)
    {
      left++;
      right=mid-1;
    }
    else if(x>mid)
    {
      left=mid+1;
      right--;
      ans+=meat[nlev-1]+1;
    }
    else
    {
      ans+=meat[nlev-1]+1;
      break;
    }
    nlev--;
  }
  if(nlev==0)ans++;
  cout<<ans<<endl;
}
