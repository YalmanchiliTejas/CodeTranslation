#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> l_l;
typedef pair<int,int> i_i;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  ll n,k;
  cin >> n >> k;
  ll ans=0;
  for(int b=k+1;b<=n;b++){
    ans+=(b-k)*(n/b)+max(0ll,n%b-k+1);
  }
  if(k==0) ans-=n;
  cout << ans << endl;
}