#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<string> jtob(string s) {
    vector<string> res;
    string cur = "";
    s += '/';
    for(auto c : s) {
        if(c == 'b') cur += 'b';
        else if('1' <= c and c <= '9') cur += string(c - '0', '.');
        else {
            // cerr << "# " << cur << endl;
            res.emplace_back(cur);
            cur = "";
        }
    }
    return res;
}

string btoj(vector<string> board) {
    string res = "";

    int N = board.size();
    for(size_t i=0; i<N; i++) {
        int cons = 0; board[i] += '#';
        for(auto c : board[i]) {
            if(c == '.') cons++;
            else {
                if(cons > 0) res += to_string(cons);
                cons = 0;
            }

            if(c == 'b') res += 'b';
        }
        if(i + 1 < N) res += '/';
    }
    return res;
}

int solve_testcase() {
    string s; cin >> s;
    if(s == "#") return 1;
    vector<string> board = jtob(s);

    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;
    swap(board[x1][y1], board[x2][y2]);

    string ans = btoj(board);
    cout << ans << endl;
    return 0;
}

int main() {
    while(!solve_testcase());
    return 0;
}

