//#include <tourist>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <tuple>
#include <deque>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <utility>
#include <complex>
#include <functional>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = (1 << 28);
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
//setprecision(15)有効数字15桁
//-std=c++14
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
struct edge {
    int to, cost;
};
int n;
ll a[100000];
ll dp[3001][30001];
ll used[3001][3001];
ll dfs(int l, int r){
    if(l>r)return 0;
    if(used[l][r]) return dp[l][r];
    used[l][r]=true;
    int count=n-(r-l+1);//取った回数の合計
    ll res;
    if(count%2==0){//自分のターン
        res=-10000000000000;
        res=max(res,dfs(l+1,r)+a[l]);
        res=max(res,dfs(l,r-1)+a[r]);
    }
    else{//相手のターン
        res=100000000000000;
        res=min(res,dfs(l+1,r)-a[l]);
        res=min(res,dfs(l,r-1)-a[r]);
    }
    dp[l][r]=res;
    return dp[l][r];
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    memset(dp,0,sizeof dp);
    memset(used,false,sizeof used);
    cout << dfs(0,n-1) << "\n";
}

