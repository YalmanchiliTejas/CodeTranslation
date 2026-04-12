#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

template<typename T> T In() { T v; cin >> v; return v; }

#define P(s) cout<<s<<endl
#define P2(b,y,f) P(((b)?y:f))
#define REP(i,b,e) for(int i=b;i<e;++i)
#define ALL(con) con.begin(), con.end()

struct Pos {
    int x = 0, y = 0;
    int cnt = 1;
    void Right() { ++x; ++cnt; }
    void Down() { ++y; ++cnt; }
};

int main() {
    auto h = In<int>();
    auto w = In<int>();
    vector<string> board(h);
    
    int num = 0;
    for (auto&& row: board) {
        cin >> row;
        num += accumulate(ALL(row), 0, [](int init, char c) {
            return init + (c=='#'?1:0);
        });
    }
    
    Pos p;
    for(;;) {
        auto right = p.x != w-1 && board[p.y][p.x + 1] == '#';
        auto down = p.y != h-1 && board[p.y + 1][p.x] == '#';
        if (right == down) {
            break;
        }
        
        if (right) {
            p.Right();
        }
        if (down) {
            p.Down();
        }
    }

    P2(num == p.cnt, "Possible", "Impossible");
    
    return 0;
}