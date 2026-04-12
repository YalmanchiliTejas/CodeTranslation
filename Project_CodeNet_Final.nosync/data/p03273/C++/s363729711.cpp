#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include<vector>

using namespace std;
typedef long long ll;
//#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  for(int i =0;i<n;++i)
//#define mod (ll)(1e9+7)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    string s[h];
    REP(i,h) cin >> s[i];
    //cout << s[0] << endl;;
    bool hi[h];
    bool wi[w];
    REP(i,h) hi[i] = true;
    REP(i,w) wi[i] = true;
    REP(i,h){
        bool f= true;
        REP(j,w) if(s[i][j] == '#') f=false;
        //REP(j,w) if(s[i][j] == '#') cout << s[i][j] << i << j<<endl;
        if(f) hi[i] = false;
    }
    REP(i,w){
        bool f=true;
        REP(j,h) if(s[j][i] =='#') f=false;
        if(f) wi[i] = false;
    }
    REP(i,h){
        if(hi[i]){
            REP(j,w) if(wi[j]) cout <<  s[i][j]; 
            cout << endl;
        }
    }
    return 0;
}