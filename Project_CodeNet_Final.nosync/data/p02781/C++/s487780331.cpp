#include"bits/stdc++.h"

using namespace std; 

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long LL;
typedef priority_queue<int> PQ_DESC;
typedef priority_queue<int, vector<int>, greater<int>> PQ_ASC;
typedef priority_queue<PII> PQ_DESC_PII;
typedef priority_queue<PII, vector<PII>, greater<PII>> PQ_ASC_PII;

#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define MP make_pair
#define SORT_ASC(c) sort(ALL(c))
#define SORT_DESC(c) sort(ALL(c), greater<typeof(*((c).begin()))>())
#define SIZE(a) int((a).size())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ROF(i,a,b) for(int i=(b-1);i>=(a);--i)
#define REP(i,n) FOR(i,0,n)
#define REP(i,n) FOR(i,0,n)
#define PER(i,n) ROF(i,0,n)

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int LARGE_INT = 1e9+100;
const int INF = 2e9+100;
const LL INF_LL = (LL)INF * 300 * 300;
const int MOD = 1e9+7;

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

LL modpow(LL a, LL n) {
    LL res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

LL modinv(LL a) {
    LL b = MOD, u = 1, v = 0;
    while (b) {
        LL t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}

LL moddev(LL a, LL b){
	return a * modinv(b) % MOD;
}

void Main()
{
    string s; cin >> s;
    int k; cin>>k;

    int n = SIZE(s);
    //dump(n)

    const int OK = 1;
    const int NG = 0;

    vector<vector<vector<LL>>> dp(n+1);
    REP(i,n+1){
        dp[i].resize(4);
        REP(j,4){
            dp[i][j].resize(2);
        }
    }

    int tmp = s[0] - '0';
    dp[0][0][OK] = 1;
    dp[0][0][NG] = 0;
    dp[0][1][OK] = tmp-1;
    dp[0][1][NG] = 1;
    dp[0][2][OK] = 0;
    dp[0][2][NG] = 0;
    dp[0][3][OK] = 0;
    dp[0][3][NG] = 0;


    FOR(i,1,n){
        int now = s[i] - '0';
        //dump(now)
        REP(kk,k+1){
            // type == ok
            if(kk != 0){
                //1~9
                dp[i][kk][OK] += dp[i-1][kk-1][OK] * 9;
            }
            //0
            dp[i][kk][OK] += dp[i-1][kk][OK] * 1;
            
            // type == ng
            if(now ==0){
                //0
                dp[i][kk][NG] = dp[i-1][kk][NG] * 1;
            }
            else{
                if(kk != 0){
                    //now
                    dp[i][kk][NG] += dp[i-1][kk-1][NG] * 1;
                    //1~now
                    dp[i][kk][OK] += dp[i-1][kk-1][NG] * (now-1);
                }
                //0
                dp[i][kk][OK] += dp[i-1][kk][NG] * 1;
            }
        }
    }

    cout << (dp[n-1][k][OK] + dp[n-1][k][NG]) << endl;

    

	return;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
    return 0;
}