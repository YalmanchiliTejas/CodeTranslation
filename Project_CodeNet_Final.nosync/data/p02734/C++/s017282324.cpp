#include <bits/stdc++.h>

using namespace std;

template <class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')
    cerr<<*sdbg++;
  cerr<<"="<<h<<","; 
  _dbg(sdbg+1, a...);
}

template<class T> ostream & operator<<(ostream & os, vector<T> V){
  os<<"[";
  for(auto vv: V) os << vv <<",";
  return os << "]";
}
template<class L, class R> ostream & operator <<(ostream & os, pair<L,R> P){
  return os <<"("<<P.first <<","<<P.second <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 3005, M = 998244353;

void add(int &w, int u) {
    w += u;
    if (w >= M) w -= M;
}

int n, S;
int a[N];
int dp[N];

int main() {
    scanf("%d %d", &n, &S);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    int ans = 0;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = S - a[i]; j >= 1; j--) {
            add(dp[j + a[i]], dp[j]);
            if (j + a[i] == S) {
                add(ans, (long long)dp[j] * (n - i + 1) % M);
            }
        }
        add(dp[a[i]], i);
        if (a[i] == S) {
            add(ans, (long long)i * (n - i + 1) % M);
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
