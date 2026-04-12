#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H,W;
    cin >> H >> W;
    vector<vector<char>> table(H,vector<char>(W));

    vector<bool> hflag(H,true);
    vector<bool> wflag(W,true);
    REP(i,H){
        REP(j,W){
            cin >> table[i][j];
            if(table[i][j]=='#'){
                hflag[i] = false;
                wflag[j] = false;
            }
        }
    }

    REP(i,H){
        if(hflag[i]==true) continue;
        REP(j,W){
            if(wflag[j]==true) continue;
            cout << table[i][j];
        }
        if(i < H-1)cout << endl;
    }


    }