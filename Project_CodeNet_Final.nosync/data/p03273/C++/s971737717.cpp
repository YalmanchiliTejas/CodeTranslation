#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll h, w;
    cin >> h >> w;
    vector<string> board(h);
    REP(i, h) cin >> board.at(i);
    REP(i, board.size()) {
        if (count(ALL(board.at(i)), '.') == w) {
            board.erase(board.begin()+i);
            i--;
        }
    }

    REP(j, board.at(0).size()) {
        bool is_to_be_removed = true;
        REP(i, board.size()) {
            if (board.at(i).at(j) != '.') {
                is_to_be_removed = false;
                break;
            }
        }
        if (is_to_be_removed) {
            REP(i, board.size()) {
                board.at(i).erase(j, 1);
            }
            j--;
        }
    }

    for (auto elem : board) {
        cout << elem << endl;
    }
    return 0;
}