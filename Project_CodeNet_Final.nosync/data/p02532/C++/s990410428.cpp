#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;
typedef vector<int> VI;
#define REP( i, m, n ) for ( int i = (int)( m ); i < (int)( n ); ++i )

int main() {
    vector<tuple<string, int, int>> cmds;
    
    int n;
    cin >> n;
    while (true) {
        string cmd;
        int arg0 = -1;
        int arg1 = 0;
        cin >> cmd;
        if (cmd == "quit") {
            break;
        } else if (cmd == "push") {
            char targ;
            cin >> arg0 >> targ;
            arg1 = static_cast<int>(targ);
        } else if (cmd == "move") {
            cin >> arg0 >> arg1;
        } else if (cmd == "pop") {
            cin >> arg0;
        }
        
        tuple<string, int, char> t(cmd, arg0, arg1);
        cmds.push_back(t);
    }
    
    vector<vector<char>> stack(n+1);
    for (auto cmd : cmds) {
        if (get<0>(cmd) == "push") {
            stack[get<1>(cmd)].push_back(get<2>(cmd));
        } else if (get<0>(cmd) == "pop") {
            cout << (char)stack[get<1>(cmd)].back() << endl;
            stack[get<1>(cmd)].pop_back();
        } else if (get<0>(cmd) == "move") {
            stack[get<2>(cmd)].push_back(stack[get<1>(cmd)].back());
            stack[get<1>(cmd)].pop_back();
        }
    }
        
    return 0;
}