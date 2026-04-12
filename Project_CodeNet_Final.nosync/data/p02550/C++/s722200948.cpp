#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i=a; i<=b; i++)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = 1e9+7;

ll n, x, m, lst, fst;
vector<ll> vec;
map<ll, int> ind;
ll sum, ans;

int main(){
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  cin.sync_with_stdio(0); cin.tie();
  cin.exceptions(cin.failbit);

  cin >> n >> x >> m;
  vec.pb(x);
  // cout << "k "<<x<<endl;
  rep(i, 1, m-1){
    ll k=(vec[i-1]*vec[i-1])%m;
    // cout << "k "<<k<<endl;
    if(k==x || ind[k]!=0){
      lst=i-1;
      fst=ind[k]; break;
    }
    vec.pb(k);
    ind[k]=i;
  }
  rep(i, fst, lst) sum+=vec[i];
  ans=((n-fst)/(lst-fst+1))*sum;
  rep(i, 0, fst-1) ans+=vec[i];
  int k=(n-fst)%(lst-fst+1);
  rep(i, 0, k-1) ans+=vec[fst+i];
  cout << ans;  
}