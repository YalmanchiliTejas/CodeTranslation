#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main() {
    char trump;
    map<char, int> m = {{'2', 0}, {'3', 1}, {'4', 2},
                        {'5', 3}, {'6', 4}, {'7', 5},
                        {'8', 6}, {'9', 7}, {'T', 8},
                        {'J', 9}, {'Q', 10}, {'K', 11},
                        {'A', 12}};
    while(cin >> trump, trump != '#') {
        vector<vector<string>> v(4, vector<string>(13));
        for(int i=0; i<4; ++i) {
            for(int j=0; j<13; ++j) {
                cin >> v[i][j];
            }
        }
        int ew = 0, ns = 0;
        int win_player = 0;
        for(int i=0; i<13; ++i) {
            int rank = -1;
            bool is_trump = false;
            char trump2 = v[win_player][i][1];
            int win_player2 = 0;
            for(int j=0; j<4; ++j) {
                int cp = (win_player+j)%4;
                if(is_trump) {
                    if(m[v[cp][i][0]] > rank && v[cp][i][1] == trump) {
                        rank = m[v[cp][i][0]];
                        win_player2 = cp;
                    }
                } else {
                    if(v[cp][i][1] == trump) {
                        is_trump = true;
                        rank = m[v[cp][i][0]];
                        win_player2 = cp;
                    } else if(rank < m[v[cp][i][0]] && trump2 == v[cp][i][1]) {
                        rank = m[v[cp][i][0]];
                        win_player2 = cp;
                    }
                }
            }
            win_player = win_player2;
            if(win_player%2 == 0) {
                ns++;
            } else {
                ew++;
            }
        }

        cout << (ew > ns ? "EW" : "NS") << ' ' << max(ew, ns) - 6 << endl;
    }
}
