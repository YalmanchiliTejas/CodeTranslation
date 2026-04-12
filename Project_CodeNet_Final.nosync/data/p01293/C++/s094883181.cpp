#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define dump(val) cerr << __LINE__ << ":\t" << #val << " = " << (val) << endl

using namespace std;

typedef long long int lli;
typedef pair<char, int> Trump;


int main() {
    char c;
    while (cin >> c, c != '#') {
        Trump trump[4][13];
        REP (i, 0, 4) REP (j, 0, 13) {
            string s;
            cin >> s;
            char suit = s[1];
            int rank;
            if (s[0] == 'T') rank = 10;
            else if (s[0] == 'J') rank = 11;
            else if (s[0] == 'Q') rank = 12;
            else if (s[0] == 'K') rank = 13;
            else if (s[0] == 'A') rank = 14;
            else rank = s[0] - '0';
            trump[i][j] = Trump(suit, rank);
        }
        int ans[2] = {0};
        int lst = 0;
        REP (i, 0, 13) {
            int ind = ([&] (vector<Trump> t) -> int {
                char suit = t[lst].first;
                REP (i, 0, 4) if (t[i].first == c) suit = c;
                vector<int> indices(t.size());
                REP (i, 0, indices.size()) indices[i] = i;
                sort(begin(indices), end(indices), [&t, &suit](int a, int b) -> bool {
                    Trump &t1 = t[a];
                    Trump &t2 = t[b];
                    if (t1.first == t2.first && t1.first == suit) return t1.second > t2.second;
                    else if (t1.first == suit) return true;
                    else if (t2.first == suit) return false;
                    else return t1.second > t2.second;
                });
                return indices[0];
            })(vector<Trump>{trump[0][i], trump[1][i], trump[2][i], trump[3][i]});
            ans[ind % 2]++;
            lst = ind;
        }
        cout << (ans[0] < ans[1] ? "EW" : "NS") << ' ' << max(ans[0], ans[1]) - 6 << endl;
    } 
    return 0;
}
