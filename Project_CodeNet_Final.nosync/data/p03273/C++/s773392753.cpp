#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define INF (1 << 30)
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
const long long mod = 1e9+7;

using namespace std;
using ll = __int64_t;
using ull = unsigned long long;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int DX[] = {1, 1, 0, -1, -1, -1, 0, 1};
int DY[] = {0, -1, -1, -1, 0, 1, 1, 1};

bool comp(const pair<int, ll>& p1, const pair<int, ll>& p2){
    return p1.second > p2.second;
}

//a, bの最大公約数．a > b
ull gcd(ull a, ull b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
//a, bの最小公倍数
ull lcm(ull a, ull b) {
    return a*(b/gcd(a, b));
}

void solve(){
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];

    vector<bool> row(h, false);
    vector<bool> col(w, false);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j] == '#'){
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for(int i = 0; i < h; i++){
        if(row[i]){
            for(int j = 0; j < w; j++){
                if(col[j]){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}