#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main(void){
    char trump;
    while (cin>>trump && trump != '#') {
        vector<vector<char> > vc(4, vector<char>(13));
        vector<vector<int> >  vi(4, vector<int>(13));
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                string s;
                cin >> s;
                vc[i][j] = s[1];
                if (s[0] >= '0' && s[0] <= '9') vi[i][j] = s[0] - '0';
                else if (s[0] == 'T') vi[i][j] = 10;
                else if (s[0] == 'J') vi[i][j] = 11;
                else if (s[0] == 'Q') vi[i][j] = 12;
                else if (s[0] == 'K') vi[i][j] = 13;
                else if (s[0] == 'A') vi[i][j] = 14;
            }
        }
        
        int lead = 0;
        int ns_score = 0, ew_score = 0;
        for (int i = 0; i < 13; i++) {
            int w_player = lead;
            char w_suit = vc[lead][i];
            int w_num = vi[lead][i];
            
            for (int j = 1; j < 4; j++) {
                int p = (lead + j) % 4;
                char p_suit = vc[p][i];
                char p_num = vi[p][i];
                if (w_suit == trump) {
                    if (p_suit == trump && p_num > w_num) w_player = p, w_suit = p_suit , w_num = p_num;
                }
                else {
                    if (p_suit == trump) w_player = p, w_suit = p_suit , w_num = p_num;
                    else if (p_suit == w_suit && p_num > w_num) w_player = p, w_suit = p_suit , w_num = p_num;
                }
            }
            
            lead = w_player;
            if (lead % 2) ew_score++;
            else ns_score++;
        }
        //cout << endl;
        if (ns_score > ew_score) cout << "NS" << " " << ns_score - 6 << endl;
        else cout << "EW" << " " << ew_score - 6 << endl;
    }
}