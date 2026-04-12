#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

typedef long long ll;
int main()
{
    int t;
    cin >> t;
    if (t>=30) puts("Yes");
    else puts("No");
    return 0;
}