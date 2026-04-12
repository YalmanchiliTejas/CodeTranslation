#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    while(1){
        char trump;
        cin >> trump;
        if(trump == '#') break;

        pair<char, int> logs[13][4];
        for(int i=0; i<4; i++){
            for(int j=0; j<13; j++){
                string s;
                cin >> s;
                int n = s[0]-'0';
                if(s[0]=='T') n=10;
                if(s[0]=='J') n=11;
                if(s[0]=='Q') n=12;
                if(s[0]=='K') n=13;
                if(s[0]=='A') n=14;
                logs[j][i].first = s[1];
                logs[j][i].second = n;
            }
        }

        int lead=0;
        vector<int> wins(4,0);
        for(int i=0; i<13; i++){
            int high=0, high_t=0;
            int winner = -1;
            char suit = logs[i][lead].first;
            for(int j=0; j<4; j++){
                int tp = (lead+j)%4;
                int rank = logs[i][tp].second;
                if(logs[i][tp].first == suit){
                    if(rank > high && high_t==0){
                        high = rank;
                        winner = tp;
                    }
                }
                if(logs[i][tp].first == trump){
                    if(rank > high_t){
                        high_t = rank;
                        winner = tp;
                    }
                }
            }
            lead = winner;
            wins[winner]++;
        }
        
        if(wins[0]+wins[2] >= 7){
            cout << "NS " << wins[0]+wins[2]-6 << endl;
        }else{
            cout << "EW " << wins[1]+wins[3]-6 << endl;
        }
    }
    return 0;
}