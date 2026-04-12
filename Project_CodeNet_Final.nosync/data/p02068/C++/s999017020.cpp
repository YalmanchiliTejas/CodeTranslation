#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <complex>
#include <numeric>
#include <string.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
double PI = 3.141592653589793238462643383279;
const double EPS = 1e-9;
const ll MOD = 998244353;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

int N;
int A[1000], B[1000];

int main() {
    cin >> N;
    rep(i,N) cin >> A[i];
    rep(i,N) B[i] = A[i];
    ll ans = 0;
    rep(i,N) {
        vector<int> v;
        for (int j = 2; j*j <= A[i]; j++) {
            if (A[i]%j) continue;
            while (A[i]%j==0) A[i] /= j;
            v.push_back(j);
        }
        if (A[i] > 1) v.push_back(A[i]);
        for (int x: v) {
            ll cnt = 0;
            rep(j,N) {
                if (B[j]%x == 0) cnt += B[j];
            }
            ans = max(ans,cnt);
        }
    }
    cout << ans << endl;
}
