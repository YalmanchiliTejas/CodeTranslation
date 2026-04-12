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

#define MAXN 10500
#define MAXD 105
#define MOD (int)(1e9 + 7)

int f[MAXN][MAXD][2];
int p[MAXN];
char s[MAXN];
int n, d, z;

int main() {
    scanf("%s%i", s + 1, &d);
    n = strlen(s + 1);
    reverse(s + 1, s + 1 + n);
    p[1] = 1 % d;
    for(int i = 2; i <= n; ++i) p[i] = p[i - 1]*10 % d;

    s[n + 1] = '0';
    f[n + 1][0][1] = 1;

    for(int i = n + 1; i >= 1; --i) 
        for(int r = 0; r < d; ++r) {
            if (f[i][r][0]) {
                // not match
                for(int j = 0; j <= 9; ++j) {
                    z = (r + j) % d;

                    f[i - 1][z][0] = (f[i - 1][z][0] + f[i][r][0]) % MOD;
                }

            }

            if (f[i][r][1]) {

                // match
                for(int j = 0; j < s[i] - '0'; ++j) {
                    z = (r + j) % d;
                    f[i - 1][z][0] = (f[i - 1][z][0] + f[i][r][1]) % MOD;
                }

                z = (r + (s[i] - '0')) % d;

                f[i - 1][z][1] = f[i][r][1] % MOD;
            }
        }

    z = (f[0][0][0] + (ll)f[0][0][1] + (MOD - 1)) % MOD;
    printf("%i\n", z);

    return 0;
}