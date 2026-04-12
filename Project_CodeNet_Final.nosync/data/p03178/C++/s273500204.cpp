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
string s;
int d;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> s>>d;
    /*
    if(s.size()==1){
            cout<<(s[0]-'0')/d<<"\n";
            return 0;
    }
    */
    int n=s.size();
    ll dp[n+1][2][d];
    memset(dp,0,sizeof dp);
    dp[0][0][0]=1;
    for (int i = 0; i <n; i++)
    {
        for(int j=0;j<2;j++){
            for(int k=0;k<d;k++){
                //cout<<i<<" "<<j<<" "<<k<<"\n";
                if(j){
                    for(int l=0;l<=9;l++){
                        dp[i+1][j][(k+l)%d]+=dp[i][j][k];
                        dp[i+1][j][(k+l)%d]%=MOD;
                    }
                }
                else{
                    for(int l=0;l<s[i]-'0';l++){
                        dp[i+1][1][(k+l)%d]+=dp[i][j][k];
                        dp[i+1][1][(k+l)%d]%=MOD;
                    }
                    dp[i+1][0][(k+(s[i]-'0'))%d]+=dp[i][j][k];
                        dp[i+1][0][(k+(s[i]-'0'))%d]%=MOD;
                }
            }
        }
    }
    cout<<(dp[n][0][0]+dp[n][1][0]-1+MOD)%MOD<<"\n";
}

