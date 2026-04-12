
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
#include<complex>

using namespace std;

#define ll long long
#define ld long double
#define INF 1e9
#define LINF (ll)INF*INF
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(int i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

#define int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

const double PI=acos(-1);
const double EPS=1e-9; //うまくいかなかったらゆるめる

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;
typedef vector<pii> vp;
typedef vector<vi> vvi;

int gcd(int a, int b){if(b==0) return a;return gcd(b,a%b);}
int lcm(int a, int b){return a/gcd(a,b)*b;}

int dp[105][2][5] = {};
signed main(void) {
    string s;
    cin >> s;
    int n = s.size();
    int k;
    cin >> k;
    dp[0][0][0] = 1;
    //k: 0でない数の個数
    rep(i,n)rep(j,2)rep(k,5){
        int lim = 9;
        if(j == 0)lim = s[i] - '0';
        rep(d,lim+1){
            if(j == 1 || d < lim){
                if(k < 4 && d){//k++
                    dp[i+1][1][k+1] += dp[i][j][k];
                }else{
                    dp[i+1][1][k] += dp[i][j][k];
                }
            }else{
                if(k < 4 && d){//k++
                    dp[i+1][0][k+1] += dp[i][j][k];
                }else{
                    dp[i+1][0][k] += dp[i][j][k];
                }
            }
        }
    }
    int ans = 0;
    ans += dp[n][0][k] + dp[n][1][k];
    cout << ans << endl;
}
