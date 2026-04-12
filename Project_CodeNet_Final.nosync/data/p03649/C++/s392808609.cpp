#include<bits/stdc++.h>
#define lson l, mid
#define rson mid+1, r
#define PII pair<int, int>
#define Size(x) (int)(x.size())
using namespace std;
typedef long long LL;
//const int MOD = 1e9+7;
const auto INF = 0x3f3f3f3f;
const int N = 1e2+5;

LL a[N], b[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
    }
    LL answer = 0;
    while(1) {
        LL temp = 0;
        bool flag = false;
        for(int i=1; i<=n; i++) {
            b[i] = 0;
            if(a[i] >= n) {
                flag = true;
                answer += a[i]/n;
                b[i] += a[i]/n;
                temp += a[i]/n;
                a[i] %= n;
            }
        }
        if(!flag)
            break;
        for(int i=1; i<=n; i++) {
            a[i] += temp - b[i];
        }
    }
    printf("%lld\n", answer);
}

