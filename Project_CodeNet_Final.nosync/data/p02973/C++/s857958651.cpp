#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()

int main() {
    int N, A;
    vector<int> colors;
    cin >> N;
    REP(i, N) {
        cin >> A;
        auto lb = lower_bound(ALL(colors), A);
        if (lb == colors.begin()) {
            colors.insert(colors.begin(), A);
        } else {
            lb--;
            *lb = A;
        }
    }
    cout << colors.size() << endl;
    return 0;
}