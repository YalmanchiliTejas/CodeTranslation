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
#include <cassert>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define REP(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(),v.end()
#define RALL(v) v.rbegin(),v.rend()
#define Cout(x) cout << x << endl;
#define check(v) rep(i,v.size()) cout << v[i] << endl;
#define vint(x) vector<int> x
#define vll(x) vector<long long> x
#define vstr(x) vector<string> x
const long long LLINF = 1LL<<60;
const int INF = 1e9;
const long long MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
#define pint pair<int,int>
using namespace std;
//オーバーフローに気をつけろよおおおおおお
//確認忘れるなよおおおおおお

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    int cnt = 1;
    vector<int> lis = {v.back()};
    rrep(i,n-1) {
        if(lis.back()<=v[i]) lis.push_back(v[i]);
        else {
            auto iter = upper_bound(ALL(lis),v[i]);
            *iter = v[i];
        }
    }
    
    cout << lis.size() << endl;
    return 0;
}