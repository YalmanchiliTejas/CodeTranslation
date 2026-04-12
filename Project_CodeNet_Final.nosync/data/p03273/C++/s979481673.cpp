#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, starter, n) for (int i = (starter); i < (int)(n); i++)

int main(){
    int H,W;
    cin >> H>> W;
    vector<vector<char>> data(H,vector<char>(W));
    rep(i,H){
        rep(j,W){
            cin >> data.at(i).at(j);
        }
    }
    //checking
    vector<int> showW;
    rep(i,H){
        int checkW=0;
        rep(j,W){
            if (data.at(i).at(j)=='.'){
                checkW++;
            }
        }
        
        if (checkW != W) showW.push_back(i);
    }
   
    vector<int> showH;
    rep(i,W){
        int checkH=0;
        rep(j,H){
            if (data.at(j).at(i)=='.') {
                checkH++;
            }
        }
        if (checkH != H) showH.push_back(i);
    }
    for(int i : showW){
        for(int j :showH){
            cout << data.at(i).at(j);
        }
        cout << endl;
    }
}