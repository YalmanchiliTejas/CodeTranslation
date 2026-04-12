#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define LINF (ll)INF*INF
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(int i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

#define int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vp;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int lcm(int a, int b){
    return a/gcd(a,b)*b;
}

int dp[10005][2][105] = {};
signed main(void) {
    string s;
    cin >> s;
    int d;
    cin >> d;
    int n = s.size();
    dp[0][0][0]++;
    rep(i,n)rep(j,2)rep(k,d)if(dp[i][j][k]){
        int lim = s[i] - '0';
        if(j)lim = 9;
        //cout << i << " " << j << " " << k << endl;
        rep(x,lim+1){
            //cout << " " << (j || x < lim) << " " << (k + x) % d << endl;
            (dp[i+1][j || x < lim][(k + x) % d] += dp[i][j][k]) %= MOD;
        }
    }
    /*
    rep(i,n+1)rep(j,2)rep(k,d)if(dp[i][j][k]){
        cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
    }*/
    cout << (MOD + dp[n][0][0] + dp[n][1][0] - 1) % MOD << endl;
}
