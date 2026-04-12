#include <stdio.h>
#include <vector>
#include <stack>
#include <functional>
#include <numeric>
#include <complex>
#include <queue>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <unordered_set>
#include <assert.h>
#include <cstring>
#include <sstream>
#include <string>
#include <algorithm>
#include <iostream>
 
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
#define pb(x) push_back(x)
#define FOR(k, n) for (int k = 0; k < n; k++)
#define FORN(k, s, n) for (int k = s; k < n; k++)
#define debug(x) printf("%s = %d\n", #x, x)
#define debug2(x, y) printf("%s = %d, %s = %d\n", #x, x, #y, y)
#define debug3(x, y, z) printf("%s = %d, %s = %d, %s = %d\n", #x, x, #y, y, #z, z)
#define debug4(x, y, z, t) printf("%s = %d, %s = %d, %s = %d, %s = %d\n", #x, x, #y, y, #z, z, #t, t)
 
#pragma warning(disable : 6031)
#pragma warning(disable : 4101)
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef complex<double> cd;
 
const int INF = 1e9;
const long long LINF = 1e18;
const double PI = acos(-1);
 
// Solution

const int MAXN = 100005;

int n, l, r, m, A[MAXN];
vector<int> P;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        A[i] = -A[i];
    }

    P = {A[0]};

    for (int i = 1; i < n; i++) {
        if (A[i] >= P.back()) {
            P.push_back(A[i]);
        } else {
            l = 0;
            r = sz(P) - 1;

            while (l != r) {
                m = (l + r) / 2;

                if (P[m] > A[i]) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }

            P[l] = A[i];
        }
    }

    printf("%d\n", sz(P));

    return 0;
}