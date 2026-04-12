#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

string k;
int d;
ll dp[200000][110][2]={0};
vector<ll> t10;

int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}

void solve(){
    cin >> k >> d;
    int n=k.length();
    dp[0][0][1]=1;
    rep(i,n){
        rep(r,d){
            int m=ctoi(k[i]);
            //cout << i << "," << r << "," << 0 << " " << dp[i][r][0] << endl;
            //cout << i << "," << r << "," << 1 << " " << dp[i][r][1] << endl;
            rep(l,10){
                dp[i+1][(r+l)%d][0]+=dp[i][r][0];
            }
            rep(l,m){
                dp[i+1][(r+l)%d][0]+=dp[i][r][1];
            }
            dp[i+1][(r+m)%d][1]+=dp[i][r][1];
            dp[i+1][r][0]%=mod;
            dp[i+1][r][1]%=mod;
            
        }
    }

    // rep(r,d){
    //     cout << n << "," << r << "," << 0 << " " << dp[n][r][0] << endl;
    //     cout << n << "," << r << "," << 1 << " " << dp[n][r][1] << endl;
    // }
    cout << (dp[n][0][0]+dp[n][0][1]-1)%mod << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}