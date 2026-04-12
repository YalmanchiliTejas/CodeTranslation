#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>>a(h,vector<char>(w));
    rep(i,h){rep(j,w)cin >> a[i][j];}
    vector<bool>print(h);
    rep(i,h)print[i]=false;
    rep(i,h){
        rep(j,w)if(a[i][j]=='#')print[i]=true;
    }
    vector<bool>print2(w);
    rep(i,w)print2[i]=false;
    rep(i,w){
        rep(j,h)if(a[j][i]=='#')print2[i]=true;
    }
    rep(i,h){
        if(print[i]){
            rep(j,w){
                if(print2[j])cout << a[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}