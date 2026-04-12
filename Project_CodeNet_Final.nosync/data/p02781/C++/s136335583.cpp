#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {0,1,0,-1,1,-1,1,-1};
ll dx[8] = {1,0,-1,0,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b) {a = b; return true;}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b) {a = b; return true;}
	else return false;
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << endl;
}
const int mod = 1e9 + 7;

ll dp[1005][5][2];

int main(){
    string s; cin >> s;
    ll K; cin >> K;
    ll n = s.size();
    dp[0][0][0] = 1;
    rep(i,n){
        rep(k,4){
            dp[i+1][k+1][1] += dp[i][k][1] * 9;
            dp[i+1][k][1] += dp[i][k][1];
            if(s[i]=='0'){
                dp[i+1][k][0] += dp[i][k][0];
            }else{
                dp[i+1][k][1] += dp[i][k][0];
                REP(j,1,s[i]-'0') dp[i+1][k+1][1] += dp[i][k][0];
                dp[i+1][k+1][0] += dp[i][k][0];
            }
        }
    }
    //print2(dp[n][K][0],dp[n][K][1]);
    cout << dp[n][K][0] + dp[n][K][1] << endl;
}