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
    ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    ll ans = 1e9;
    ans = min(ans,a*x+b*y);
    ans = min(ans,c*2*max(x,y));
    if(x>y){
        ans = min(ans,c*2*y+a*(x-y));
    }else{
        ans = min(ans,c*2*x+b*(y-x));
    }
    cout << ans << endl;

    return 0;
}