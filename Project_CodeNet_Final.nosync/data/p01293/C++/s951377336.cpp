#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define rep(i, n) for(int i=0; i<(n); ++i)

int main(){
    char Trump;
    while(cin >> Trump, Trump != '#'){
        vector<vector<string> > Cards(4, vector<string>(13, ""));
        rep(i, 4)rep(j, 13)cin >> Cards[i][j];
        int NS = 0, EW = 0, winner = 0;
        rep(turn, 13){
            char suit = Cards[winner][turn][1];
            rep(player, 4){
                if([&](const string& s, const string& t){
                        for(const auto x: {Trump, suit})if(s[1] == x ^ t[1] == x)return t[1] == x;
                        for(const auto x: "AKQJT")if(s[0] == x || t[0] == x)return s[0] != x;
                        return s < t;
                   }(Cards[winner][turn], Cards[player][turn]))winner = player;
            }
            (winner & 1? EW: NS)++;
        }
        cout << (NS < EW? "EW ": "NS ") << max(NS, EW) - 6 << '\n';
    }
    return 0;
}