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
using PLL = pair<ll, ll>;
const int INF = numeric_limits<int>::max();
const ll INFL = numeric_limits<ll>::max();


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

ll factorial(ll n) {
    ll res = 1;
    for (ll i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

bool fn_is_prime(ll n) {
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
}

bool isOK(int index, int key, vector<ll>& a) {
    if (a[index] >= key) return true;
    else return false;
}

int binary_search(int key, vector<ll>& a) {
    int ng = -1;
    int ok = a.size();

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key, a)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main()
{
    int n; cin >> n;
    int a[n][26];
    memset(a, 0, sizeof(a));

    rep(i,n) {
        string s; cin >> s;
        rep(j,s.length()) {
            a[i][s[j]-'a']++;
        }
    }

    vector<int> count(26, INF);
    rep(j,26) {
        rep(i,n) {
            count[j] = min(count[j], a[i][j]);
        }
    }
    rep(i,26) {
        if (count[i] == INF) continue;
        rep(j,count[i]) {
            cout << (char)('a' + i);
        }
    }
    cout << endl;
}
