#include<bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define REP(i, n) for(int i=0;i<(n);++i)
#define RANGE(i, a, b) for(int i=(a);i<(b);++i)
#define RREP(i, n) for(int i=(n)-1;i>= 0;--i)

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define pque priority_queue
#define umap unordered_map
#define BIG 2000000000
#define VERYBIG 1000000000000000ll
#define PI 3.141592653589793238
#define dcout cout<<fixed<<setprecision(20)

const long long dx[]={1,0,-1,0,1,1,-1,-1}, dy[]={0,-1,0,1,1,-1,1,-1};
const long long MOD = 1e9+7;

// typedef long long ll;
#define int long long
#define double long double

template<typename T> inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template<typename T> inline T LCM(T a,T b){T c=GCD(a,b);a/=c;return a*b;}
template<typename T> inline T nCr(T a,T b){T i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
template<typename T> inline T nHr(T a,T b){return nCr(a+b-1,b);}

typedef pair<int, int> INTP;
typedef vector<int> INTV;
struct edge2 {int to, cost;};
struct edge3 {int from, to, cost;};

signed main(void){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int K, A, B; cin >> K >> A >> B;
  if(A-B<=0 and A < K) cout << -1 << endl;
  else if(A-B<=0 and A>=K) cout << 1 << endl;
  else {
    int plus = A-B;
    int ans = 1;
    K -= A; ans += (K+plus-1)/plus * 2;
    cout << ans << endl;
  }
}