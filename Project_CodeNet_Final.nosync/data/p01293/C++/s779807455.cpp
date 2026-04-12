#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

string rankStr = "23456789TJQKA";

int main()
{
    for(;;){
        char trump;
        cin >> trump;
        if(trump == '#')
            return 0;

        vector<vector<int> > rank(4, vector<int>(13));
        vector<vector<char> > suit(4, vector<char>(13));
        for(int i=0; i<4; ++i){
            for(int j=0; j<13; ++j){
                string s;
                cin >> s;
                rank[i][j] = rankStr.find(s[0]);
                suit[i][j] = s[1];
            }
        }

        int led = 0;
        vector<int> win(2, -6);
        for(int i=0; i<13; ++i){
            int maxScore = -1;
            int winPlayer;
            for(int j=0; j<4; ++j){
                int score = rank[j][i];
                if(suit[j][i] == trump)
                    score += 100;
                else if(suit[j][i] == suit[led][i])
                    score += 50;

                if(score > maxScore){
                    maxScore = score;
                    winPlayer = j;
                }
            }
            ++ win[winPlayer&1];
            led = winPlayer;
        }

        if(win[0] > win[1])
            cout << "NS " << win[0] << endl;
        else
            cout << "EW " << win[1] << endl;
    }
}