#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(i, j, k) for(int i=j ; i<k ; i++)
#define REP(i, j) FOR(i, 0, j)
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;

vector<int> es[8];

int rep(int i, vector<bool> used) {

    int result = 0;

    used[i] = true;
    bool is_final = true;
    REP(j, es[i].size()) {
        if (!used[es[i][j]]) {
            is_final = false;
            result += rep(es[i][j], used);
        }
    }

    if (is_final) {
        REP(j, used.size()) if(!used[j]) return 0;
        return 1;
    } else {
        return result;
    }
}

int main() {

    int N, M; cin >> N >> M;
    REP(i, M) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        es[y].push_back(x);
        es[x].push_back(y);
    }

    vector<bool> used(N); REP(i, N) used[i] = false;

    cout << rep(0, used) << endl;

    return 0;
}
