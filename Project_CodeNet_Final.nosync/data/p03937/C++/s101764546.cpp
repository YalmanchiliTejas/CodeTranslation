#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    int h, w;
    cin >> h >> w;
    int cnt = 0;
    rep(i, h) rep(j, w) {
        char a;
        cin >> a;
        if (a == '#') cnt++;
    }
    if (cnt == h+w-1) cout << "Possible\n";
    else cout << "Impossible\n";
}