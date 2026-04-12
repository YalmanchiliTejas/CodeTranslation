#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define debug(x) cout << "debug " << x << endl;
const int INF = 100000000;
using namespace std;

int main(){
    char suit;
    while(cin >> suit, suit != '#'){
        vector<vector<pair<int ,char>>> v(4);
        char inp[2];
        rep(i,4){
            rep(j,13){
                cin >> inp;
                if(inp[0] == 'K') v[i].emplace_back(make_pair(13, inp[1]));
                else if(inp[0] == 'Q') v[i].emplace_back(make_pair(12, inp[1]));
                else if(inp[0] == 'J') v[i].emplace_back(make_pair(11, inp[1]));
                else if(inp[0] == 'T') v[i].emplace_back(make_pair(10, inp[1]));
                else v[i].emplace_back(make_pair(inp[0] - '0', inp[1]));
            }
        }

        char base = v[0][0].second;
        int score[2] = {0};
        rep(i,13){
            int maxi = -1;
            int player;
            rep(j,4){
                if(v[j][i].second == suit && v[j][i].first > maxi){
                    maxi = v[j][i].first;
                    player = j;
                }
            }
            if(maxi == -1){
                rep(j,4){
                    if(v[j][i].second == base && v[j][i].first > maxi){
                        maxi = v[j][i].first;
                        player = j;
                    }
                }
            }
            score[player % 2]++;
            base = v[player][i + 1].second;
        }
        if(score[0] > score[1]){
            cout << "NS " << score[0] - 6 << endl;
        }else{
            cout << "EW " << score[1] - 6 << endl;
        }
    }
}