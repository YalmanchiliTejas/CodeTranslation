/*
    Author:zeke
    
    pass System Test!
    GET AC!!
*/
#include <iostream>
#include <queue>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <map>
#include <iomanip>
#include <utility>
#include <stack>
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rep3(var, min, max) for (ll(var) = (min); (var) < (max); ++(var))
#define repi3(var, min, max) for (ll(var) = (max)-1; (var) + 1 > (min); --(var))
#define Mp(a, b) make_pair((a), (b))
#define F first
#define S second
#define Icin(s) \
    ll(s);      \
    cin >> (s);
#define Scin(s) \
    ll(s);      \
    cin >> (s);
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<P> VP;
ll MOD = 1e9 + 7;
ll INF = 1e18;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string t;
    cin >> t;
    reverse(all(t));
    ll d;
    cin>>d;
    ll dp[t.size() + 1][d][2];
    rep(i,t.size()+1)rep(j,d)rep(k,2)dp[i][j][k]=0;
    dp[0][0][0] = 1;
    rep(i,t.size()){
        rep(j,d){
            rep(k,10){
                ll f = (j + k) % d;
                if(k>t[i]-'0'){
                    dp[i + 1][f][1] += dp[i][j][0] + dp[i][j][1];
                }else if(k==t[i]-'0'){
                    dp[i + 1][f][1] += dp[i][j][1];
                    dp[i + 1][f][0] += dp[i][j][0];
                }else{
                    dp[i + 1][f][0] += dp[i][j][1] +dp[i][j][0];
                }
                dp[i+1][f][0]%=MOD;
                dp[i+1][f][1]%=MOD;
            }
        }
    }
    cout << (dp[t.size()][0][0]+MOD-1)%MOD << endl;
}