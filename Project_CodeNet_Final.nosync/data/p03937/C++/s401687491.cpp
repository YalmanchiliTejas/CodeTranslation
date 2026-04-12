#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e13;
const int mod = 1e9+7;
#define ll long long
char a[10][10];
int h,w;
signed main() {
    cin >> h >> w;
    rep(i,h) {
        string s;
        cin >> s;
        rep(j,w) {
            a[i][j]=s[j];
        }
    }
    rep(i,h) {
        rep(j,w) {
            if(a[i][j]=='#') {
                bool f = true;
                FOR(k,i+1,h) {
                    rep(l,j) {
                        if(a[k][l]=='#') {
                            //cout << k<<" "<<l << endl;
                            f = false;
                        }
                    }
                }
                if(!f) {
                    cout << "Impossible" << endl;
                    return 0;
                }
            }
        }
    }
    
    cout << "Possible" << endl;
    return 0;
}

