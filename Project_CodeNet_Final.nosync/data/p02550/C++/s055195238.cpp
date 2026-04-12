#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

const double pi = 3.141592653589793238462643383279;
using namespace std;
using namespace __gnu_pbds;
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
 
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
 
//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
 
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)

const long double EPS = 1e-6, PI = acos((long double)-1);

//ここから編集

ll arr[101010];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(7);


  ll N, X, M; cin >> N >> X >> M;

  vector<ll> v;
  v.push_back(X);

  arr[X] = 1;
  int cnt = 0;
  for(cnt=1; cnt<M; cnt++){
    X = (X*X)%M;
    if(arr[X] != 0) break;
    v.push_back(X);
    arr[X] = cnt+1;
  }
  /* cntは周期長を表す */
  ll k = arr[X];

  ll ans = 0;
  for(int i=0; i<k-1; i++){
    ans += v[i];
  }
  //cout << k << " " << ans << endl;
  N-=k-1;

  ll sum = 0;
  for(int i=k-1; i<v.size(); i++){
    sum += v[i];
  }

  /* cntはv.size()に等しい */
  if(cnt-k+1 == 1){
    ans += v[k-1] * N;
  }else{
    ans += sum * (N/(cnt-k+1));
    N %= (cnt-k+1);

    for(int i=k-1; i<k-1+N; i++) ans += v[i];
  }
  cout << ans << endl;



  return 0;
}