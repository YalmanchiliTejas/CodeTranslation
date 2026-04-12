// JavaProgram.cpp
// Author : Priydarshi Singh (@dryairship)
// One cat just leads to another. One bug leads to two others.

#include <bits/stdc++.h>
using namespace std;

// I like my types defined.
typedef long long           ll;
typedef pair<int, int>      pii;
typedef pair<ll, ll>        pll;
typedef vector<int>         vi;
typedef vector<ll>          vl;
typedef vector<pii>         vii;
typedef vector<pll>         vll;
typedef set<int>            si;
typedef map<string, int>    msi;
typedef map<int, int>       mii;

// Traditional science is all about finding "hashtag define"s.
#define fr(i, n)            for(int i=0; i<(n); ++i)
#define frC(i, n, c)        for(int i=0; (i<(n)) && (c); ++i)
#define frA(i, a, n)        for(int i=a; i<=(n); ++i)
#define frD(i, a, n)        for(int i=a; i>=(n); --i)
#define fill(a)             memset(a, 0, sizeof(a))
#define fill1(a)            memset(a, -1, sizeof(a))
#define revsort(a, b)       sort(a, b, greater<int>())
#define ff                  first
#define ss                  second
#define pb                  push_back 
#define dout                if(DEBUGGING) cout
#define dbg                 if(DEBUGGING) 
#define endl                "\n"

// When you realize MOD > INF...
int DEBUGGING    =          0;
const int INF    =          1000000000;
const int MOD    =          1000000007;
const ll LINF    =          1e18;
const double PI  =          3.1415926535897932;
const double EPS =          1e-7;

// I'D SPAM. Hehe.
ll gcdEx                    (ll a, ll b, ll *x, ll *y){if(!a){*x=0;*y=1;return b;} 
ll x1,y1,gcd=gcdEx          (b%a,a,&x1,&y1); *x=y1-(b/a)*x1;*y=x1; return gcd;}
ll modI(ll b, ll m)         {ll x,y;gcdEx(b,m,&x,&y);return (x%m+m)%m;}
ll modD(ll a, ll b)         {return (modI(b,MOD)*(a%MOD))%MOD;}
ll modS(ll a, ll b)         {return ((a%MOD)-(b%MOD)+MOD)%MOD;}
ll modP(ll x, ll y)         {ll r=1; x%=MOD; while(y>0){if(y&1){r=(r*x)%MOD;} y=y>>1; x=(x*x)%MOD;} return r;}
ll modA(ll a, ll b)         {return ((a%MOD)+(b%MOD))%MOD;}
ll modM(ll a, ll b)         {return ((a%MOD)*(b%MOD))%MOD;}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll dp[100005][105][2];
// dp[i][j][0] = number of i digit integers with (sum of digits) % D = j, when we can go upto 9
// dp[i][j][1] = number of i digit integers with (sum of digits) % D = j, when we can go upto current digit in k

void solve(int TEST_CASE){
    string k; cin >> k;
    int d; cin >> d;
    int n = k.length();
    fill(dp);
    fr(i,10) dp[1][i%d][0] += 1;
    fr(i,k[n-1]-'0'+1) dp[1][i%d][1] += 1;
    frA(i,2,n){ // num digits
        fr(j,d){ // j such that no. of i-1 digit integers with sumofDig%d=j
            fr(dd, 10){ // currentDigit
                //dout << "adding " << dp[i-1][j] << " to dp["<<i<<"]["<<(dd+j)%d<<"] for dd="<<dd<<", j="<<j<<endl;
                dp[i][(dd+j)%d][0] = (dp[i][(dd+j)%d][0]+dp[i-1][j][0])%MOD;
            }
            fr(dd, k[n-i]-'0'){
                dp[i][(dd+j)%d][1] = (dp[i][(dd+j)%d][1]+dp[i-1][j][0])%MOD;
            }
            dp[i][(k[n-i]-'0'+j)%d][1] = (dp[i][(k[n-i]-'0'+j)%d][1]+dp[i-1][j][1])%MOD;
        }
    }
    dbg{
        fr(i,11){
            fr(j,d+2){
                cout << dp[i][j][0] <<",";
            }
            cout << endl;
        }
    }
    dout << endl;
    dbg{
        fr(i,11){
            fr(j,d+2){
                cout << dp[i][j][1] <<",";
            }
            cout << endl;
        }
    }
    cout << (dp[n][0][1]-1+MOD)%MOD <<endl;
}

int main(int argc, char* argv[]){
    if(argc==2 && argv[1][1]=='v') DEBUGGING = 1;
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin.exceptions(cin.failbit);
    int nTestCases=1;
    //cin >> nTestCases;
    frA(i,1,nTestCases) solve(i);
    return 0;
}