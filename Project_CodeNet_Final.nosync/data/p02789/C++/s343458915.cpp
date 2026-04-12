///cREATED bY BERNARB.01
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef priority_queue<int,vector<int>,greater<int>> pqil;
typedef priority_queue<int> pqig;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef priority_queue<pii> pqiig;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef map<int, int> mii;
#define mid ((l+r)/2)
#define PB push_back
#define PP pop_back
#define PF push_front
#define DF pop_front
#define F first
#define S second
#define MP make_pair
#define C continue
#define B break
#define R return
#define sz(v) (int)(v).size()
#define len(s) (int)(s).length()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define clr(arr, x) memset((arr), (x), sizeof (arr))
#define loop(n) for(int i=0; i<(n); i++)
#define jloop(n) for(int j=0; j<(n); j++)
#define rloop(n) for(ll i=(n)-1; i>=0; i--)
const ll N = 2e5+9;
const ll INF = 2e17+423;
const ll mod = 1e9+7; //998244353;
const ld pi = acos(-1.0);
const ld cmpf = 1e-9;
//__int128_t
#define endl '\n'
ll po(ll,ll);














int main() {
  /*#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  #endif // ONLINE_JUDGE*/
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  if(m==n) cout << "Yes\n";
  else cout << "No\n";
  R 0;
}
/*

*/



































ll po(ll x, ll n){
  if(n==0) R 1;
  ll y = po(x, n/2);
  y = ((y)*(y));
  if(n%2) y = (y*(x));
  R y;
}
