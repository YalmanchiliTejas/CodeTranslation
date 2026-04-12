#include<bits/stdc++.h>
#define lson l, mid, i<<1
#define rson mid+1, r, i<<1|1
#define PII pair<int, int>
using namespace std;
typedef long long LL;
//const int MOD = 1e9+7;
const auto INF  = 0x3f3f3f3f;
const int N = 2e5+5;

int a[N], b[N*2];

int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    int L = N-5, R = N-5;
    b[L] = a[1];
    for(int i=2; i<=n; i++) {
        if(i%2 == 0) {
            b[--L] = a[i];
        } else
            b[++R] = a[i];
    }
    if(n%2==0) {
        for(int i=L; i<=R; i++)
            printf("%d%c", b[i], i==R ? '\n' : ' ');
    } else {
        for(int i=R; i>=L; i--)
            printf("%d%c", b[i], i==L ? '\n' : ' ');
    }
}
