#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }



int main(int argc, char const *argv[]) {
  int n;
  cin >> n ;
  vector<int> h(n) ;
  rep(i,n) cin >> h[i] ;
  int ans=1;

  for(int i=n-1; i>0; i--){
    bool can=true;
    int c=h[i];
    for(int j=i-1; j>=0; j--){
      if(c<h[j]) can=false;
    }
    if(can) ans++;
  }
  cout << ans << endl;


  return 0;
}
