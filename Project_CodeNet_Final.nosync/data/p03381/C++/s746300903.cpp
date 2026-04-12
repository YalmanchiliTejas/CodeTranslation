#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(a) (a).begin(), (a).end()

int N, X[200000];

int main() {
    cin >> N;
    int tmp[200000];
    REP(i, N) {
        cin >> X[i];
        tmp[i] = X[i];
    }
    sort(tmp, tmp + N);
    int c1 = tmp[N / 2 - 1], c2 = tmp[N / 2];

    REP(i, N) {
        if (X[i] < c2) cout << c2 << endl;
        else cout << c1 << endl;
    }
    return 0;
}