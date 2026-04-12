#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF 2147483647//int max
const int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int h,w;
    cin >> h >> w;
    vector< vector<char>> table(h,vector<char>(w));
    rep(i,h)rep(j,w)cin >> table.at(i).at(j);
    vector<int> horizon;
    vector<int> virtical;
    rep(i,h){
        bool b = true;
        rep(j,w)if(table.at(i).at(j) != '.')b = false;
        if(b)horizon.push_back(i);
    }
    rep(i,w){
        bool b = true;
        rep(j,h)if(table.at(j).at(i) != '.')b = false;
        if(b)virtical.push_back(i);
    }
    rep(i,h){
        if(find(horizon.begin(),horizon.end(),i) == horizon.end()){
            rep(j,w){
                if(find(virtical.begin(),virtical.end(),j) == virtical.end()){
                    cout << table.at(i).at(j);
                }
            }
            cout << endl;
        }else{
        }
    }
    return 0;
}

/*
やっほい！
　　　　　　　やほほい！
　　　　+　　 　*
　　　 ∧∧　　. ∧∞∧　*
*　ヽ(=´ω｀)人(´ω｀*)ﾉ
　.～（ O x.） （ 　 O)～　+
。*　 　∪　　　　∪
*/