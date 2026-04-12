#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <numeric>
#include <complex>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define PI 3.1415926535897932384626433832795

#define fill(x, v)  fillchar(x, v, sizeof(x))
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector< pii >   vpii;


#define MAXN 3010

ll  a[MAXN];
ll  f[MAXN][MAXN];
int n;

int main() {
    scanf("%i", &n);
    for(int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    for(int l = 1; l <= n; ++l)
        for(int i = 0; i + l <= n; ++i) {
            int j = i + l - 1;
            if (l % 2 == n % 2) {
                f[i][j] = max(f[i + 1][j] + a[i], f[i][j - 1] + a[j]);
            } else {
                f[i][j] = min(f[i + 1][j], f[i][j - 1]);
            }
        }

    printf("%lld\n", 2*f[0][n - 1] - accumulate(a, a + n, 0LL));

    return 0;
}