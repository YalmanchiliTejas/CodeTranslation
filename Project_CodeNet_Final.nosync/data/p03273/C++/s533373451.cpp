#include <bits/stdc++.h>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H,W;
    cin >> H >> W;
    vector<vector<char>> chart(H,vector<char>(W));
    REP(i,H)REP(j,W)cin >> chart.at(i).at(j);
    vector<bool> erase1(H);
    REP(i,H){
        REP(j,W){
            if(chart.at(i).at(j) == '#')break;
            if(j == W-1)erase1.at(i) = 1;
        }
    }
    REP(i,H)if(erase1.at(H-1-i))chart.erase(chart.begin()+H-1-i);
    H = chart.size();
    vector<bool> erase2(W);
    REP(i,W){
        REP(j,H){
            if(chart.at(j).at(i) == '#')break;
            if(j == H-1)erase2.at(i) = 1;
        }
    }
    REP(i,W)if(erase2.at(W-1-i))REP(j,H)chart.at(j).erase(chart.at(j).begin()+W-1-i);
    REP(i,chart.size()){
        REP(j,chart.at(0).size())cout << chart.at(i).at(j);
        cout << "\n";
    }
}