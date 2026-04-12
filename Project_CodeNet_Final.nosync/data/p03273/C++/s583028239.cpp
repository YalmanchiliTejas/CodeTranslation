#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long ;
using P = pair<ll, ll>;
const ll INF = 1e16;

void solver(int H, int W, vector<vector<char>> &area){

    bool flg = true;
    for(int i = 0; i != H; ++i){
        for(int j = 0; j != W; ++j){
            if(area.at(i).at(j) == '#') flg = false;
        }
        if(flg){
            for(int j = 0; j != W; ++j){
                area.at(i).at(j) = 'N';
            }
        }
        flg = true;
    }

    cerr << "called"s << endl;

    for(int j = 0; j != W; ++j){
        for(int i = 0; i != H; ++i){
            if(area.at(i).at(j) == '#') flg = false;
        }
        if(flg){
            for(int i = 0; i != H; ++i){
                area.at(i).at(j) = 'N';
            }
        }
        flg = true;
    }

    cerr << "called"s << endl;

    return;    
}

int main(){

    int H, W;
    cin >> H >> W;
    vector<vector<char>> area(H, vector<char>(W));
    for(int i = 0; i != H; ++i){
        for(int j = 0; j != W; ++j){
            cin >> area.at(i).at(j);
        }
    }

    solver(H, W, area);

    bool flg = false;
    for(int i = 0; i != H; ++i){
        for(int j = 0; j != W; ++j){
            if(area.at(i).at(j) != 'N'){
                cout << area.at(i).at(j);
                flg = true;
                }
        }
        if(flg) cout << endl;
        flg = false;
    }

    return 0;
}