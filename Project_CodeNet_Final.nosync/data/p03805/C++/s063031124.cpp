#include<bits/stdc++.h>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
typedef long long ll;
typedef pair<ll,ll> P;
const int INF=INT_MAX / 3;
const ll LINF=LLONG_MAX / 3LL;
#define CONST 1000000007
#define EPS (1e-8)
#define PB push_back
#define MP make_pair
#define sz(a) ((int)(a).size())
#define reps(i,n,m) for(int i=(n);i<int(m);i++)
#define rep(i,n) reps(i,0,n)
#define SORT(a) sort((a).begin(),(a).end())
ll mod(ll a,ll m){return (a%m+m)%m;}
int dx[9]={0,1,0,-1,1,1,-1,-1,0},dy[9]={1,0,-1,0,1,-1,1,-1,0};
ll n,m;

bool es[10][10];
ll dp[1 << 10][10];

string toB(int x, int r = 8) {
  string s = "";
  while(r-->0) {
    s = ((x % 2 == 0)? "0" : "1") + s;
    x /= 2;
  }
  return s;
}

ll rec(int s, int x) {
  //printf("(%s, %d)\n", toB(s,n).c_str(), x);
  if(!(s & (1<<x))) return 0;
  if(dp[s][x] > 0) return dp[s][x];
  dp[s][x] = 0;
  int nx = s & (~(1 << x));
  rep(i, n) {
    if(!es[x][i]) continue;
    dp[s][x] += rec(nx, i);
  }
  //cout << toB(s, n) <<" "<< x <<" "<< dp[s][x] <<endl;
  return dp[s][x];
}


int main(){
  cin >> n >> m;
  rep(i, m) {
    int a,b;
    cin >> a >> b ;
    es[--a][--b] = true;
    es[b][a] = true;
  }

  dp[1][0] = 1;

  ll ans = 0;
  reps(i, 1,n) {
    ans += rec((1<<n)-1, i);
  }
  cout<<ans<<endl;

  return 0;
}
