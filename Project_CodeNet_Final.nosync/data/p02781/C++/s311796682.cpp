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
#include <bitset>
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
ll mod = 1e9 + 7;
ll MOD = 1e9 + 7;
ll INF = 1e18;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    ll K;
    cin>>K;
    ll n=s.size();
    ll dp[n+1][K+1][2];
    rep(i,n+1)rep(j,K+1)rep(k,2)dp[i][j][k]=0;
    reverse(all(s));
    dp[0][K][0]=1;
    rep(i,n){
        ll temp=s[i]-'0';
        rep(j,K+1){
            if(j==0){
                dp[i+1][j][0]+=dp[i][j][0]+dp[i][j][1];
                continue;
            }
            rep3(k,1,10){
                if(k>temp){
                    dp[i+1][j-1][1]+=dp[i][j][0]+dp[i][j][1];
                }else if(k==temp){
                    dp[i+1][j-1][1]+=dp[i][j][1];
                    dp[i+1][j-1][0]+=dp[i][j][0];
                }else{
                    dp[i+1][j-1][0]+=dp[i][j][0]+dp[i][j][1];
                }
            }
            if(temp==0){
                dp[i+1][j][0]+=dp[i][j][0];
                dp[i+1][j][1]+=dp[i][j][1];
            }else{
                dp[i+1][j][0]+=dp[i][j][0]+dp[i][j][1];
            }
            
        }
    }
    cout<<dp[n][0][0]<<endl;
}
