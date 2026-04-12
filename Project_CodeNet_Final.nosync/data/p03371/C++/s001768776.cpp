#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define reps(i, m, n) for (int i = m; i < n; i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(void){
    int a, b, c, x, y;
    scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
    int ab = min(a+b, c*2);
    a = min(a, c*2);
    b = min(b, c*2);
    
    ll ans = ab*min(x, y)+a*max(0, x-y)+b*max(0, y-x);
    printf("%lld\n", ans);
    
    return 0;
}