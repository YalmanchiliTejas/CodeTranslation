#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>

using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()
 
int main(){
    int h, w;
    cin >> h >> w;
    char a[h][w];
    rep(i, h)rep(j, w)cin >> a[i][j];

    bool dh[100] = {false};
    bool dw[100] = {false};
    rep(i, h){
        bool flag = true;
        rep(j, w)if(a[i][j] == '#')flag = false;
        if(flag)dh[i] = true;
    }
    rep(i, w){
        bool flag = true;
        rep(j, h)if(a[j][i] == '#')flag = false;
        if(flag)dw[i] = true;
    }

    rep(i, h)if(!dh[i]){
        rep(j, w){
            if(dw[j])continue;
            cout << a[i][j];
        }cout << endl;
    }
}