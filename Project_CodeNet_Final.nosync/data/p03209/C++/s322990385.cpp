#include<iostream>
#include<iomanip>
#include<algorithm>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<deque>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<tuple>
#include<utility>
#include<vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<vector<int>> vvi;

#define rep(i, a, n)  for(int i=a; i<n; i++)
#define REP(i, n)  for(int i=0; i<(int)(n); i++)
#define REPS(i, n)  for(int i=1; i<=(int)(n); i++)
#define PER(i, n) for(int i=(int)(n)-1; i>= 0; i--)
#define PERS(i, n)  for(int i=(int)(n); i>0; i--)
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i!=(c).end(); i++)
#define RFOR(i, c)  for(__typeof((c).rbegin()) i=(c).rbegin(); i!=(c).end(); i++)
#define ALL(container)  (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) (container).size()
#define FILL0(n)  setfill('0') << right << setw(n)
#define mp(a, b)  make_pair(a, b)
#define toLower(c)  c+0x20
#define toUpper(c)  c-0x20
#define pb  push_back
#define eb  emplace_back

const int INF = 1e9;
const long long LLINF = 1e18;
const ll MOD = 1000000007;
const int MSIZE = 100007;
const double Pi = 3.14159265358979323146;

ull a[51], p[51];

ull f(ull n, ull x){
  ull nn = (n==0?0:n-1);
  ull nx = (x==0?0:x-1);
  if(n==0LL){
    return (x<=0 ? 0 : 1);
  }
  else if(x<=1LL + a[n-1]){
    return f(nn, nx);
  }
  else{
    nx = (x>=2-a[n-1]?x-2-a[n-1]:0);
    return p[n-1] + 1LL + f(n-1, x-2-a[n-1]);
  }
}

int main(){
  ull n, x; cin >> n >> x;
  a[0]=1LL; p[0]=1LL;
  for(ull i=1; i<=n; i++){
    a[i] = a[i-1]*2LL+3LL;
    p[i] = p[i-1]*2LL+1LL;
  }
  cout << f(n, x) << endl;
}
