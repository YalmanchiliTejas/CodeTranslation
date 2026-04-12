/**
    Sweet!
**/
#include <bits/stdc++.h>

#define fr first
#define sc second
#define mk make_pair
#define pb push_back
#define pp pop_back()
#define ll long long
#define ld long double
#define OK puts("OK");
#define sz(s) (int)s.size()
#define all(s) s.begin(), s.end()

using namespace std;

inline int min(int a, int b) {
    return (a > b) ? b : a;
}

inline int max(int a, int b) {
    return (a > b) ? a : b;
}

const int N = 2e5 + 10;
const int inf = 1e9+10;
const ll linf = 1e18+9;

ll n, m, k, t, a[N], b[N], id[N], ama, bma, ami = inf, bmi = inf, dma, dmi = inf;

bool cmp(int x,int y) {
    return a[x] < a[y];
}

int main() {
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d",&a[i], &b[i]);
        if(a[i] > b[i])
            swap(a[i], b[i]);
        id[i] = i;
        ama = max(ama, a[i]);
        ami = min(ami, a[i]);
        bma = max(bma, b[i]);
        bmi = min(bmi, b[i]);
    }
    ll ret = (ama - ami) * (bma - bmi);
    sort(id + 1,id + n + 1, cmp);
    for(int i = 1; i <= n; i++) {
        dma = max(dma, b[id[i]]);
        dmi = min(dmi,b[id[i]]);
        ret = min(ret, (max(dma, a[id[n]]) - min(dmi, a[id[i+1]])) * (bma - ami));
    }
    printf("%lld\n", ret);
    return 0;
}
