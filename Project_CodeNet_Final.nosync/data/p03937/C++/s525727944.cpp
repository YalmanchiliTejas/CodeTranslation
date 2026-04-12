#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    bool c[h+1][w+1];
    rep(i,h){
        rep(j,w){
            c[i][j]=false;
        }
    }
    c[0][0]=true;
    int x=0,y=0;
    while(1){
        if(y==h-1 && x==w-1) break;
        if(s[y][x+1]=='#'){
            c[y][x+1]=true;
            ++x;
            continue;
        }else{
            if(s[y+1][x]=='#'){
                c[y+1][x]=true;
                ++y;
                continue;
            }else{
                cout << "Impossible" << "\n";
                return 0;
            }
        }
    }
    rep(i,h){
        rep(j,w){
            if(!c[i][j] && s[i][j]=='#'){
                cout << "Impossible" << "\n";
                return 0;
            }
        }
    }
    cout << "Possible" << "\n";
    return 0;
}   