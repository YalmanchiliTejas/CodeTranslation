#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using Graph = vector<vector<pii>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<bool> isx(N);
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        isx[i] = (c == 'x');
    }

    vector<bool> issheep(N);
    for (int i = 0; i < 4; ++i) {
        issheep[0] = i & 1, issheep[1] = i & 2;
        for (int j = 1; j < N - 1; ++j)
            issheep[j + 1] = issheep[j - 1] ^ isx[j] ^ !issheep[j];
        if (issheep[0] != issheep[N - 2] ^ isx[N - 1] ^ !issheep[N - 1])
            continue;
        if (issheep[1] != issheep[N - 1] ^ isx[0] ^ !issheep[0])
            continue;
        for (int j = 0; j < N; ++j)
            cout << (issheep[j] ? 'S' : 'W');
        cout << endl;
        return 0;
    }

    cout << -1 << endl;
    return 0;
}
