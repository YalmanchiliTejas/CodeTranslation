#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int, int> P;

void solve(char trump) {
    vector<vector<string> > C(4, vector<string>(13));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            cin >> C[i][j];
        }
    }
    int EW = 0, NS = 0;
    int leader = 0;
    for (int i = 0; i < 13; i++) {
        vector<pair<int, P> > now_trick;
        for (int j = 0; j < 4; j++) {
            char now_c = C[j][i][0], now_suit = C[j][i][1];
            int number;
            if (now_c >= '2' && now_c <= '9') {
                number = now_c - '0';
            }
            else if (now_c == 'T') number = 10;
            else if (now_c == 'J') number = 11;
            else if (now_c == 'Q') number = 12;
            else if (now_c == 'K') number = 13;
            else number = 14;
            int priority;
            if (now_suit == trump) priority = 2;
            else if (now_suit == C[leader][i][1]) priority = 1;
            else priority = 0;
            now_trick.push_back(make_pair(priority, P(number, j)));
        }
        sort(now_trick.rbegin(), now_trick.rend());
        int winner = now_trick[0].second.second;
        if (winner == 0 || winner == 2) NS++;
        else EW++;
        leader = winner;
    }
    if (EW > NS) cout << "EW " << EW - 6 << endl;
    else cout << "NS " << NS - 6 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    char trump;
    while (true) {
        cin >> trump;
        if (trump == '#') break;
        solve(trump);
    }
    return 0;
}
