#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  ll n,a[200010];
  cin>>n;
  ll md=1000000007;
  ll ans=0;
  ll tmp=0;

  for(ll i=0;i<n;i++){
    cin>>a[i];
    ans+=a[i];
    ans%=md;
  }



  for(ll i=0;i<n;i++){
    ans-=a[i];
    if(ans<0)ans+=md;
    tmp+=a[i]*ans;
    tmp%=md;
  }

  // tmp%=md;
  cout<<tmp<<endl;
  return 0;
}
