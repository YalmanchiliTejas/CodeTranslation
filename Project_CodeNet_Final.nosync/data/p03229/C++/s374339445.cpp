#include <stdio.h>
#include <algorithm>
#include <deque>
#include <math.h>

using namespace std;

typedef long long ll;

#define N 110000

ll a[N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
        sort(a, a + n);
        if (n == 1 || n == 0) puts("0");
        if (n == 2) printf("%lld\n", a[1] - a[0]);
        else {
            int i = 0, j = n - 1;
            deque<ll> q;
            q.push_back(a[j--]);
            q.push_back(a[i++]);
            while (i <= j) {
                ll f = q.front(); ll b = q.back();
                if (i == j) {
                    if (abs(f - a[i]) > abs(b - a[i])) {
                        q.push_front(a[i++]); break;
                    } else {
                        q.push_back(a[j--]); break;
                    }
                }
                if (abs(f - a[i]) + abs(b - a[j]) > abs(f - a[j]) + abs(b - a[i])) {
                    //printf("1  %lld %lld\n", a[i], a[j]);
                    q.push_front(a[i++]); q.push_back(a[j--]);
                } else {
                    //printf("2  %lld %lld\n", a[i], a[j]);
                    q.push_front(a[j--]); q.push_back(a[i++]);
                }
            }
            ll res = 0;
            ll x = q.front(); q.pop_front(); //printf("%lld\n", x);
            while (!q.empty()) {
                ll y = q.front(); q.pop_front();
                //printf("%lld\n", y);
                res += abs(x - y);
                x = y;
            }
            printf("%lld\n", res);
        }
    }
    return 0;
}