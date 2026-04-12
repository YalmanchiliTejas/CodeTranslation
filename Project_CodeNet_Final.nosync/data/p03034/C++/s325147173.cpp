#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
#define N 100010
ll n,s[N];
ll solve(ll k){
  vector<ll> L,R;
  for(int i=0;i<n;i+=k)L.push_back(s[i]);
  for(int i=n-1;i>=0;i-=k)R.push_back(s[i]);
  ll ans=0,sum=0;
  for(int i=0;i<L.size()&&i<R.size();i++){
    if((n-1-i*k)%k==0&&(n-1-i*k)<=i*k)break;
    sum+=L[i]+R[i];
    if(n-1-i*k>k) ans=max(ans,sum);
  }
  return ans;
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++)cin>>s[i];
  ll ans=0;
  for(int k=1;k<n;k++){
    ans=max(ans,solve(k));
  }
  cout<<ans<<endl;
  return 0;
}
