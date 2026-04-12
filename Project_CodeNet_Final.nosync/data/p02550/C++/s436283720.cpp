#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>
#include <bits/stdc++.h>

#define int long long

struct edge {
    int to;
    int cost;
};

using namespace std;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vb = vector<bool>;
using qi = queue<int>;
using P = pair<int, int>;
using graph = vector<vector<edge>>;
// using graph = vector<vector<int>>;


#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define delim(i, n) cout << (i == n-1 ? "\n" : " ");

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int inf = 1LL << 60;
// const int inf = 100000000;
const int mod = 1000000007;

const int maxn = 1e5+1;
int n, m, a;
vi rem(maxn);

vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};

signed main () {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    cin >> n >> a >> m;
    int cnt = n;
    int loop = n;
    int ret = a;
    rem[0] = a;
    FOR(i, 1, n){
        a = (a*a)%m;
        int flag = false;
        REP(j, i) {
            if (a == rem[j]) {
                flag = true;
                loop = i-j;
            }
        }
        if (flag) {
            cnt = i;
            break;
        } else rem[i] = a;
        ret += a;
    }
    int loopsum = 0;
    for (int i = cnt - loop; i < cnt; i++) {
        loopsum += rem[i];
    }
    
    ret += ((n-cnt)/loop)*loopsum;
    REP(i, (n-cnt)%loop) {
        ret += rem[i+cnt-loop];
    }
    cout << std::fixed << std::setprecision(10) << ret << "\n";
}