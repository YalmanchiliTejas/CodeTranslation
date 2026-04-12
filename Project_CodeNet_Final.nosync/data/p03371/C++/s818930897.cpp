#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = 1001001001;
    REP(c_cnt, max(x, y) * 2 + 1) {
        int a_cnt = max(0, (x * 2 - c_cnt + 2 - 1) / 2);
        int b_cnt = max(0, (y * 2 - c_cnt + 2 - 1) / 2);
        ans = min(ans, a_cnt * a + b_cnt * b + c_cnt * c);
    }
    cout << ans << endl;
    
    return 0;
}
