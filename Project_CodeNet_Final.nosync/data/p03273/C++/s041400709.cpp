#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
const int mod= 1e+9+7;

int main() {
    int H,W; cin>>H>>W;
    vector<vector<char>>h(H,vector<char>(W));
    rep(i,H){
        rep(j,W)cin>>h[i][j];
    }
    int cnt;
    //cout<<endl;
    //
    rep(i,H){
        cnt=0;
        rep(j,W){
            if(h[i][j]=='.')cnt++;
            }
             if(cnt==W){
                rep(k,W){
                    h[i][k]=' ';
                }
        }
    }
    //
    int ww=W;
    rep(i,W){
        cnt=0;
        rep(j,H){
            if(h[j][i]=='.' || h[j][i]==' ')cnt++;
            }
             if(cnt==H){
                 ww--;
                rep(k,H){
                    h[k][i]=' ';
                }
        }
    }
    rep(i,H){
        cnt=0;
        rep(j,W){
            if(h[i][j]==' ')continue;
            cnt++;
            cout<<h[i][j];
            if(cnt==ww)cout<<endl;
        }
    }
}