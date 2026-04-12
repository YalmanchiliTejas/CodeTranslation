#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <cassert>
#include <numeric>
#include <functional>
#include <cassert>
//#include <numeric>
#pragma warning(disable:4996) 
 
typedef long long ll;
typedef unsigned long long ull;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

ull a[500][500];

void solve()
{
    int n;
    scanf("%d", &n);
    vector<int> s(n), t(n);
    vector<ull> u(n), v(n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    for (i = 0; i < n; i++) {
        scanf("%llu", &u[i]);
    }
    for (i = 0; i < n; i++) {
        scanf("%llu", &v[i]);
    }

    vector<ull> res(n*n);
#define P(i,j) ((i)*n+(j))
    int j, k;
    for (i = 0; i < 64; i++) {
        vector<int> ans(n*n, -1);
        vector<int> v0, v1;
        vector<int> flag0(2*n), flag1(2*n);
        for (j = 0; j < n; j++) {
            if (s[j] == 0 ) {
                if (u[j] & (1ull << i)) {
                    for (k = 0; k < n; k++) {
                        if (ans[P(j, k)] == 0) {
                            printf("-1\n"); return;
                        }
                        ans[P(j, k)] = 1;
                    }
                }
                else {
                    flag0[2*j] = 1;
                    v0.push_back(j);
                }
            }
            else {
                if (!(u[j] & (1ull << i))) {
                    for (k = 0; k < n; k++) {
                        if (ans[P(j, k)] == 1) {
                            printf("-1\n"); return;
                        }
                        ans[P(j, k)] = 0;
                    }
                }
                else {
                    flag0[2*j+1] = 1;
                    v0.push_back(j);
                }
            }
        }

        for (j = 0; j < n; j++) {
            if (t[j] == 0) {
                if (v[j] & (1ull << i)) {
                    for (k = 0; k < n; k++) {
                        if (ans[P(k, j)] == 0) {
                            printf("-1\n"); return;
                        }
                        ans[P(k, j)] = 1;
                    }
                }
                else {
                    flag1[2*j] = 1;
                    v1.push_back(j);
                }
            }
            else {
                if (!(v[j] & (1ull << i))) {
                    for (k = 0; k < n; k++) {
                        if (ans[P(k, j)] == 1) {
                            printf("-1\n"); return;
                        }
                        ans[P(k, j)] = 0;
                    }
                }
                else {
                    flag1[2*j+1] = 1;
                    v1.push_back(j);
                }
            }
        }

        if ((int)v0.size() == 1) {
            int cnt0[2] = {0,0};
            for (k = 0; k < (int)v1.size(); k++) {
                int cnt[2] = { 0,0 };
                for (j = 0; j < n; j++) {
                    if (j == v0[0]) continue;
                    if (ans[P(j, v1[k])] == 0) cnt[0]++;
                    if (ans[P(j, v1[k])] == 1) cnt[1]++;
                }
                if (flag1[2*v1[k]] && !cnt[0]) {
                    if (ans[P(v0[0], v1[k])] == 1) {
                        printf("-1\n"); return;
                    }
                    ans[P(v0[0], v1[k])] = 0; cnt0[1]++;
                }
                else if (flag1[2*v1[k]+1] && !cnt[1]) {
                    if (ans[P(v0[0], v1[k])] == 0) {
                        printf("-1\n"); return;
                    }
                    ans[P(v0[0], v1[k])] = 1; cnt0[0]++;
                }
            }
            for (k = 0; k < (int)v1.size(); k++) {
                if (ans[P(v0[0], v1[k])] < 0) {
                    ans[P(v0[0], v1[k])] = (flag0[2*v0[0]]? 0 : 1);
                }
            }
        }
        else if ((int)v1.size() == 1) {
            int cnt0[2] = {0,0};
            for (k = 0; k < (int)v0.size(); k++) {
                int cnt[2] = {0,0}, cnt0[2] = {0,0};
                for (j = 0; j < n; j++) {
                    if (j == v1[0]) continue;
                    if (ans[P(v0[k], j)] == 0) cnt[0]++;
                    if (ans[P(v0[k], j)] == 1) cnt[1]++;
                }
                if (flag0[2*v0[k]] && !cnt[0]) {
                    if (ans[P(v0[k], v1[0])] == 1) {
                        printf("-1\n"); return;
                    }
                    ans[P(v0[k], v1[0])] = 0; cnt0[1]++;
                }
                else if (flag0[2*v0[k]+1] && !cnt[1]) {
                    if (ans[P(v0[k], v1[0])] == 0) {
                        printf("-1\n"); return;
                    }
                    ans[P(v0[k], v1[0])] = 1; cnt0[0]++;
                }
            }
            for (k = 0; k < (int)v0.size(); k++) {
                if (ans[P(v0[k], v1[0])] < 0) {
                    ans[P(v0[k], v1[0])] = (flag1[2*v1[0]]? 0: 1);
                }
            }
        }
        else {
            for (j = 0; j < (int)v0.size(); j++) {
                for (k = 0; k < (int)v1.size(); k++) {
                    ans[P(v0[j], v1[k])] = (j+k)%2;
                }
            }
        }

        for (j = 0; j < (int)v0.size(); j++) {
            int cnt[2] = { 0,0 };
            for (k = 0; k < n; k++) {
                assert(ans[P(v0[j], k)] >= 0);
                if (ans[P(v0[j], k)] == 0) cnt[0]++;
                else cnt[1]++;
            }
            if (flag0[2*v0[j]] && !cnt[0]) {
                printf("-1\n"); return;
            }
            if (flag0[2*v0[j]+1] && !cnt[1]) {
                printf("-1\n"); return;
            }
        }

        for (k = 0; k < (int)v1.size(); k++) {
            int cnt[2] = { 0,0 };
            for (j = 0; j < n; j++) {
                assert(ans[P(j, v1[k])] >= 0);
                if (ans[P(j, v1[k])] == 0) cnt[0]++;
                else cnt[1]++;
            }
            if (flag1[2*v1[k]] && !cnt[0]) {
                printf("-1\n"); return;
            }
            if (flag1[2*v1[k]+1] && !cnt[1]) {
                printf("-1\n"); return;
            }
        }

        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                res[P(j, k)] = (res[P(j,k)] | (ans[P(j,k)]? (1ull<<i): 0));
            }
        }

    }

    for (j = 0; j < n; j++) {
        for (k = 0; k < n; k++) {
            printf("%llu", res[P(j, k)]);
            if (k < n - 1)printf(" ");
        }
        printf("\n");
    }

    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T;
    scanf("%d", &T);
    int t;
    for(t=0; t<T; t++) {
        //printf("Case #%d: ", t+1);
        solve();
    }
#endif
    return 0;
}

