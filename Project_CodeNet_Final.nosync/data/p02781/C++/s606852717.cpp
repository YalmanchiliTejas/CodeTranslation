#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <utility>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>
#include <cstdio>
#include <map>
#include <list>
#include <stdio.h>
#include <sstream>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define _upgrade ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define pb push_back
//ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
//ll lcm(ll x, ll y) {return x / gcd(x, y) * y;}
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const ll mod = 1e9 + 7;
const ll inf = 1<<29;
const long double pi = 3.14159265358979323846;

// ****************************************CODE***************************************//

int dp[105][4][2];

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int K;
    cin >> K;
    dp[0][0][0] = 1;

    rep(i,n)rep(j,4)rep(k,2) {
        int nd = s[i]-'0';
        rep(d,10){
            int ni = i+1, nj = j, nk = k;
            if(d!=0) nj++;
            if(nj>K) continue;
            if(k==0){
                if(d>nd) continue;
                if(d<nd) nk = 1;
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }
    int ans = dp[n][K][0] + dp[n][K][1];
    cout << ans << endl;
    return 0;
}