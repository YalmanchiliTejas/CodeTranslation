#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repeat(i,s,n) for(int (i)=s; (i)<(n); (i)++)
#define revrep(i,n) for(int (i)=(n)-1;i>=0; i--)

vector<ll> sz(51);

ll solve(ll n, ll x) {
  if(n==0) {
    if(x==0) {
      return 0;
    }
    if(x==1) {
      return 1;
    }
    //cout << "Something goes wrong."<<endl;
    return 0;
  }
  if(1+sz[n-1]>=x) {
    return solve(n-1,x-1);
  }
  if(x<=2+2*sz[n-1]) {
    return solve(n-1,sz[n-1]) + 1LL + solve(n-1,x-sz[n-1]-2);
  }
  return 1LL+2*solve(n-1,sz[n-1]);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(std::numeric_limits<float>::max_digits10);
  sz[0]=1;
  repeat(i,1,51) {
    sz[i]=2*sz[i-1]+3;
  }
  ll n,x;
  cin>>n>>x;
  cout << solve(n,x) << endl;
  return 0;
}
