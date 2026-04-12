#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 2e5 + 5;

int n;
pii a[N];
int res[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }

    sort(a + 1,a + n + 1);

    for(int i = 1;i <= n;i++) {
        if(i <= n / 2) {
            res[a[i].second] = a[n / 2 + 1].first;
        }else {
            res[a[i].second] = a[n / 2].first;
        }
    }

    for(int i = 1;i <= n;i++) {
        printf("%d\n", res[i]);
    }

    return 0;
}
