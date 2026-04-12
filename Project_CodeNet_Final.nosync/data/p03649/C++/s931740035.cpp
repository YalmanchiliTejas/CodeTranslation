#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define CLR(A, X) memset(A, X, sizeof(A))
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-10;
int dcmp(double x){if(fabs(x)<eps) return 0; return x<0?-1:1;}
const LL INF = 0x3f3f3f3f;
const LL MOD = 1e9+7;
const int N = 2e5+5;

const LL MAXN = 1e16+1000;

int main() {
    LL n;
    scanf("%lld", &n);
    priority_queue<LL> Q;
    for(int i = 0; i < (int)n; i++) {
        LL x;
        scanf("%lld", &x);
        Q.push(x);
    }
    LL cnt = 0, ans = 0;
    for(;;) {
        LL x = Q.top(); Q.pop();
        if(x+cnt < n) break;
//        printf("x = %lld cnt = %lld\n", x, cnt);
        LL y = (x+cnt)/n;
        x = (x+cnt)%n-y-cnt;
        Q.push(x);
        cnt += y;
    }
    printf("%lld\n", cnt);
    return 0;
}
