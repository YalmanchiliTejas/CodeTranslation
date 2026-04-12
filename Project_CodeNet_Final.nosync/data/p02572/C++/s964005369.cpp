#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,s=0,mod=1e9+7,ans=0;cin>>n;
  lvector A(n);rep(i,n) {cin>>A[i];s=(s+A[i])%mod;}
  rep(i,n) {
    s-=A[i];
    if(s<0) s+=mod;
    ans+=(A[i]*s)%mod;
    ans%=mod;
  }
  print(ans);
  return 0;
}