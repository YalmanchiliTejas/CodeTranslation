#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i< (int)(n); i++)
int main(){
    int H,W,f=0,c=0;
    cin >> H >> W;
    vector<vector<char>> grid(H,vector<char> (W));
    rep(i,H){
        rep(j,W){
            cin >> grid.at(i).at(j);
        }
    }
    rep(i,H){
        f=0;
        rep(j,W){
            if(grid.at(i).at(j)=='#') {
                f=1;
                break;
            }
        }
        if(f==0){
            rep(j,W) grid.at(i).at(j)='-';
        }
    }
    rep(i,W){
        f=0;
        rep(j,H){
            if(grid.at(j).at(i)=='#') {
                f=1;
                break;
            }
        }
        if(f==0){
            rep(j,H) grid.at(j).at(i)='-';
            c++;
        }
    }
    rep(i,H){
        int C=0;
        rep(j,W){
            if(grid.at(i).at(j)=='-') continue;
            C++;
            cout << grid.at(i).at(j);
            if(C==(W-c)) cout << endl;
            //else cout << ' ';

        }
    }
}