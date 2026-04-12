#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define DUMP(x) cout << #x << " = " << (x) << endl;
#define REP(i, n) for(size_t i = 0; i < (n); i++)
#define REPR(i, n) for(size_t i = (n); i >= 0; i--)
#define FOR(i, a, b) for(size_t i = (a); i < (b); i++)
#define FOREACH(x,a) for(auto& (x) : (a))

const int INF = 1e9;
const int MOD = 1e9 + 7;

int N;
vector<int> X;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vector<int> sort_X;
    REP(i, N) {
        int x; cin >> x;
        X.push_back(x);
        sort_X.push_back(x);
    }
    sort(sort_X.begin(), sort_X.end());
    REP(i, N) {
        if(X[i] > sort_X[N / 2 - 1]) cout << sort_X[N / 2 - 1] << "\n";
        else cout << sort_X[N / 2] << "\n";
    }
}