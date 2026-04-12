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


void Main()
{
    int n;cin>>n;
    vector<LL> a(n);
    REP(i,n){
        cin>>a[i];
    }
    int offset = 3;

    vector<map<int,LL>> dp0(n);
    vector<map<int,LL>> dp1(n);
    REP(i,n){
        //dp0[i].resize(n,-INF_LL);
        //dp1[i].resize(n,-INF_LL);
        //dp0[i].resize(10,-INF_LL);
        //dp1[i].resize(10,-INF_LL);
    }
    //REP(j,n){
    //    dp1[0][j] = a[0];
    //}
    REP(i,n){
        int start = max(0,i/2 -2*offset);
        int end = min(n/2+1, i/2  +2*offset);
        FOR(j,start,end){
            dp0[i][j] = -INF_LL;
            dp1[i][j] = -INF_LL;
        }
    }
    dp0[0][0] = 0;
    dp1[0][1] = a[0];

    FOR(i,1,n){
        int start = max(0,i/2 -offset);
        int end = min(n/2+1, i/2  +offset);
        //int start = 0;
        //int end = n;

        FOR(j,start,end){
            dp0[i][j] = max(dp0[i-1][j],dp1[i-1][j]);
            if(j == 0){
                
            }
            else if(j == 1){
                dp1[i][j] = a[i];
            }
            else{
                dp1[i][j] = dp0[i-1][j-1] + a[i];
            }
        }
    }

    cout << max(dp0[n-1][n/2], dp1[n-1][n/2])<<endl;


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