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
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n);
    rep(i,m) {
        int ai, bi;
        cin >> ai >> bi;
        ai--; bi--;
        a[ai].push_back(bi);
        a[bi].push_back(ai);
    }

    int path[n];
    rep(i,n) path[i] = i;

    int ans = 0;
    do {
        //rep(i,n) cout << path[i] << " ";
        //cout << endl;
        int reach = 1;
        rep(i,n-1) {
            int flag = 0;
            rep(j,a[path[i]].size()) {
                if(a[path[i]][j] == path[i+1]) {
                    flag = 1;
                }
            }
            if (flag == 0) {
                reach = 0;
                break;
            }
        }
        if (reach)
            ans++;
    } while(next_permutation(path+1, path+n));

    cout << ans << endl;
                
    return 0;
}
