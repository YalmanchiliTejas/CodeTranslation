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
  ll n,inf=1e9+10;cin>>n;
  lvector A(n);rep(i,n) cin>>A[i];
  reverse(ALL(A));
  lvector dp(100000,inf);
  rep(i,n) {
    auto it=upper_bound(ALL(dp),A[i]);
    *it=A[i]; 
  }
  print(lower_bound(ALL(dp),inf)-dp.begin());
  return 0;
}