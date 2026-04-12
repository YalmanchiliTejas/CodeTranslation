#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define SORT(a) sort(a.begin(), a.end())
#define RSORT(a) sort(a.rbegin(), a.rend())
#define REP(i, n) for (int i = 0; i < n; i++)
#define RREP(i, n) for (int i = n; 0 <= i; i--)
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define FORSTEP(i, start, end, step) for (int i = start; i < end; i += step)
#define RFOR(i, start, end) for (int i = start; end <= i; i--)
#define ALL(a) a.begin(), a.end()
#define MOD(a) a %= 1000000007
typedef long long ll;
const int INF32 = 2147483647;
const ll INF64  = 9223372036854775807;
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    string S;
    cin >> N >> S >> K;

    REP(i, N) {
        if (S[i] != S[K - 1]) {
            S[i] = '*';
        }
    }

    cout << S << endl;

    return 0;
}