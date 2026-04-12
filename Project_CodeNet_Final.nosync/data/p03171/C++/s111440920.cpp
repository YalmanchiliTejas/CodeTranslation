#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
#define CLR(t,v) memset(t,(v),sizeof(t))
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}


int nextInt() { int x; scanf("%d", &x); return x;}

const int MAX_N = 3005;
bool vis[MAX_N][MAX_N];
ll dp[MAX_N][MAX_N];
int A[MAX_N];

ll f(const int a, const int b, const int turn) {
  if (vis[a][b]) {
    return dp[a][b];
  }
  ll res = 0;
  if (a > b) {
    res = 0;
  } else if (turn == 0) { // maximize
    res = max(f(a+1, b, 1-turn) + A[a],
              f(a, b-1, 1-turn) + A[b]);
  } else { // minimize
    res = min(f(a+1, b, 1-turn) - A[a],
              f(a, b-1, 1-turn) - A[b]);
  }
  vis[a][b] = true;
  return dp[a][b] = res;
}

int main2() {
  CLR(vis, 0);
  int N = nextInt();
  REP(i, N) A[i] = nextInt();
  ll ans = f(0, N-1, 0);
  cout << ans << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
