#include<bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<int> ok_gyou;
    vector<int> ok_retsu;
    vector<vector<char>> a(H, vector<char>(W));
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            char A;
            cin >> A;
            a.at(i).at(j) = A;
        }
    }
    for (int i = 0; i < H; i++){
        bool all_white = true;
        for (int j = 0; j < W; j++){
            if(a.at(i).at(j) == '#'){
                all_white = false;
                break;
            }
        }
        if(all_white == false){
            ok_gyou.push_back(i);
        }
    }
    for (int j = 0; j < W; j++){
        bool all_white = true;
        for (int i = 0; i < H; i++){
            if (a.at(i).at(j) == '#'){
                all_white = false;
                break;
            }
        }
        if (all_white == false){
            ok_retsu.push_back(j);
        }
    }
    for (int i: ok_gyou){
        for (int j : ok_retsu){
            cout << a.at(i).at(j);
        }
        cout <<endl;
    }
}