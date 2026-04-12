#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int i = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define MP make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int MOD = 1e9 + 7;

int calc(vector<int> v) {
    int ret = 0;
    rep(i, v.size() - 1) { ret += abs(v[i + 1] - v[i]); }
    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    sort(All(A));
    ll res = 0, tmp = 0;
    if(N % 2) {
        for(int i = 0; i < N; i++) {
            if(i < N / 2 + 1) {
                if(i == N / 2 || i == N / 2 - 1) {
                    tmp -= A[i];
                } else
                    tmp -= 2 * A[i];
            } else {
                tmp += 2 * A[i];
            }
        }
    } else {
        for(int i = 0; i < N; i++) {
            if(i < N / 2 + 1) {
                if(i == N / 2)
                    tmp -= A[i];
                else
                    tmp -= 2 * A[i];
            } else {
                if(i == N / 2 + 1)
                    tmp += A[i];
                else
                    tmp += 2 * A[i];
            }
        }
    }

    res = max(tmp, res);

    tmp = 0;
    if(N % 2) {
        for(int i = 0; i < N; i++) {
            if(i >= N / 2) {
                if(i == N / 2 || i == N / 2 + 1) {
                    tmp += A[i];
                } else
                    tmp += 2 * A[i];
            } else {
                tmp -= 2 * A[i];
            }
        }
    } else {
        for(int i = 0; i < N; i++) {
            if(i >= N / 2) {
                if(i == N / 2)
                    tmp += A[i];
                else
                    tmp += 2 * A[i];
            } else {
                if(i == N / 2 - 1)
                    tmp -= A[i];
                else
                    tmp -= 2 * A[i];
            }
        }
    }
    res = max(res, tmp);

    cout << res << endl;
    return 0;
}