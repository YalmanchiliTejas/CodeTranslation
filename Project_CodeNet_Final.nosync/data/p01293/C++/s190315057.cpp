#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <utility>

using namespace std;

#define rep(i,b) for(int i=0;i<int(b);i++)

int _rank[128];
char trump;
string card[4][13];

int main(){
    int i;
    for(i=2;i<10;i++) _rank['0'+i] = i;
    for(char c:"TJQKA") _rank[c]=i++;
    while(cin >> trump && trump!='#'){
        rep(i,4)rep(j,13)cin>>card[i][j];
        int next = 0;
        int score[] = {0,0};
        rep(i,13){
            int winner = 0, max = 0;
            bool used = false;
            char led = card[next][i][1];
            rep(j,4){
                int r = _rank[card[j][i][0]];
                char s = card[j][i][1];
                if(used){
                    if(s == trump && r > max){
                        tie(max,winner) = tie(r,j);
                    }
                }else{
                    if(s == trump){
                        used = 1;
                        tie(max,winner) = tie(r,j);
                    } else if(s == led && r > max){
                        tie(max,winner) = tie(r,j);
                    }
                }
            }
            next = winner;
            score[winner%2]++;
        }

        if(score[0] > score[1]) cout<<"NS "<<score[0]-6<<endl;
        else cout<<"EW "<<score[1]-6<<endl;
    }
}