#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include<limits.h>
#include<iomanip>
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(),v.end()
#define RALL(v) v.rbegin(),v.rend()
#define check(v) rep(i,v.size()) cout << v[i] << " ";\
cout << endl
#define INF 1e8
typedef long long ll;
using namespace std;
//オーバーフローに気をつけろよおおおおおお
//確認忘れるなよおおおおおお

int main() {
    int h, w; cin >> h >> w;
    vector<string> v(h);
    rep(i,h){
        cin >> v[i];
    }
    int now=0;
    bool flag = true;
    rep(i,h){
        rep(j,w){
            if(v[i][j]=='#') {
                if(j<now) flag = false;
                else now = j;
            }
        }
    }
    if(flag) cout << "Possible" << endl;
    else cout << "Impossible" << endl;

    return 0;
}