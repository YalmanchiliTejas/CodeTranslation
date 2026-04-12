#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <iomanip>
#include <bitset>
#include <set>
#include <map>
#include <stdio.h>
#include <numeric>
#include <cstring>

#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep1(i,n) for (int i = 1; i < (n); i++)
#define FOR(i,a,b) for (int i=(a); i < (b); i++)
#define MOD 1000000007 //10^9+7
#define TEN5 100000 //10^5
#define TEN9 1000000000 //10^9
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int INF = numeric_limits<int>::max();

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) res += m;
    return res;
}

//greatest common divisor
long long gcd(ll a, ll b) 
{
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

//least common multiple
long long lcm(ll a, ll b)
{
    return a / gcd(a, b) * b ;
}

int main()
{
    int h, w; cin >> h >> w;
    char a[h][w];
    rep(i,h) {
        rep(j,w) {
            cin >> a[i][j];
        }
    }
    
    int flag = 1;
    set<PII> s;
    for(int i = 0; i < h; i++) {
        if (a[i][0] == '.') {
            int line = 1;
            rep(j,w) {
                if (a[i][j] == '#')
                    line = 0;
            }
            if (line) {
                rep(j,w) {
                    s.emplace(i,j);
                }
            }
        }
    }

    for(int i = 0; i < w; i++) {
        if (a[0][w] == '.') {
            int line = 1;
            rep(j,h) {
                if (a[j][i] == '#')
                    line = 0;
            }
            if (line) {
                rep(j,h) {
                    s.emplace(j,i);
                }
            }
        }
    }

    rep(i,h){
        int flag = 0;
        rep(j,w) {
            auto itr = s.find(make_pair(i,j));
            if (itr == s.end()) {
                cout << a[i][j];
                flag = 1;
            }
        }
        if (flag)
            cout << endl;
    }
        
    return 0;
}

