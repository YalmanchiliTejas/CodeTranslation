#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;cin>>h>>w;
    const char M = 110;
    char grid[M][M];
    bool lok[M], cok[M];
    rep(i,h){
        rep(j,w){
            cin>>grid[i][j];
        }
    }
    rep(i, h){
        bool flag=false;
        rep(j, w){
            if(grid[i][j]=='#'){
                flag = true;
                break;
            }
        }
        lok[i] = flag;
    }
    rep(j,w){
        bool flag = false;
        rep(i,h){
            if(grid[i][j]=='#'){
                flag = true;
                break;
            }
        }
        cok[j]=flag;
    }
    rep(i, h){
        if(lok[i]){
            rep(j,w){
                if(cok[j]){
                    cout<<grid[i][j];
                }
            }
        cout<<endl;
        }
    }

}