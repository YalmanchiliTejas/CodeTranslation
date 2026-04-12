#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<functional>
#include<numeric>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<set>
#include<bitset>
#include<random>
#pragma region
using namespace std;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define rep(i,n) FOR(i,0LL,n)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;i--)
#define rrep(i,n) RFOR(i,0LL,n)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define COUNT(a,y,x) upper_bound(all(a), y) - lower_bound(all(a), x)
#define UNIQUE(a) sort(all(a)); a.erase(unique(all(a)), a.end())
#define pb push_back
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef map<ll, ll> MAP;
const ll inf = 1LL << 61;
const ll mod = 1000000007LL;
//const ll mod = 998244353LL;

ll n = 0, m = 0, ans = 0, tmp = 0, ma = -inf, mi = inf;
string s;
ll dx[9] = { 0,1,0,-1,0,1,1,-1,-1 }, dy[9] = { 0,0,1,0,-1,1,-1,1,-1 };
#define endl '\n'
#pragma endregion
#define MAX 222222



ll a[MAX];


int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);



  cin >> n;
  rep(i, n) cin >> a[i];
  unordered_map<ll, ll> mp;
  set<ll> st;
  st.insert(-inf);
  st.insert(inf);
  ma = 1;
  rep(i, n) {
    auto it = st.lower_bound(a[i]);
    it--;
    tmp = *it;
    if (tmp == -inf) {
      st.insert(a[i]);
      mp[a[i]]++;
      ans++;
    }
    else {
      mp[tmp]--;
      ans--;
      if (mp[tmp]==0) {
        st.erase(tmp);
      }
      st.insert(a[i]);
      mp[a[i]]++;
      ans++;
    }
  }
  cout << ans << endl;



  return 0;
}
