#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define reps(i,n) for (int i=1;i<=(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rreps(i,n) for (int i=(n);i>0;i--)
#define all(v) (v).begin(),(v).end()
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>
template<class T> inline bool chmin(T &a, T b) {if (a>b) {a = b; return 1;} return 0;};
template<class T> inline bool chmax(T &a, T b) {if (a<b) {a = b; return 1;} return 0;};
typedef long long int ll;
const long long INF = 1LL << 60;

ll l[51], p[51];

ll calc(ll N, ll X){
  if (X==0) return 0;
  else if (N==0) return 1;
  else if (X<=l[N-1]+1) return calc(N-1,X-1);
  else {
    X -= l[N-1] + 1;
    return p[N-1] + 1 + calc(N-1,X-1);
  }
}

int main(){
  int N; cin >> N;
  ll X; cin >> X;

  l[0] = 1;
  p[0] = 1;
  rep(i,N) l[i+1] = 2*l[i] + 3;
  rep(i,N) p[i+1] = 2*p[i] + 1;

  cout << calc(N,X) << endl;



  
  // cout << fixed << setprecision(10);
  
  return 0;
}
