#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n+1); ++i)
using namespace std;
using ll = long long;
const int INF = -100100100;
typedef pair<int,int> P;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> a(h,vector<char>(w));
    rep(i,h)rep(j,w)cin >> a[i][j];
    rep(i,h){
        bool as = true;
        rep(j,w){
            if(a[i][j]=='#')as=false;
        }
        if(as)rep(j,w)a[i][j] = 's';
    }
    rep(j,w){
        bool as = true;
        rep(i,h){
            if(a[i][j]=='#')as=false;
        }
        if(as)rep(i,h)a[i][j] = 's';
    }
    rep(i,h){
        bool chk = false;
        rep(j,w){
            if(a[i][j]=='s'){
                continue;
            }else{
                chk=true;
            }
            cout << a[i][j];
        }
        if(chk)cout << endl;
        else continue;
    }
    return 0;
}