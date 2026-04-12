#include"bits/stdc++.h"

using namespace std; 

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long LL;
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef pair<LL, LL> PLL;
typedef vector<PLL> VPLL;
typedef priority_queue<LL> PQ_DESC;
typedef priority_queue<LL, VL, greater<LL>> PQ_ASC;
typedef priority_queue<PII> PQ_DESC_PII;
typedef priority_queue<PII, vector<PII>, greater<PII>> PQ_ASC_PII;
typedef priority_queue<VL> PQ_DESC_VL;
typedef priority_queue<VL, vector<VL>, greater<VL>> PQ_ASC_VL;
typedef priority_queue<PLL> PQ_DESC_PLL;
typedef priority_queue<PLL, vector<PLL>, greater<PLL>> PQ_ASC_PLL;

#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define MP make_pair
#define SORT_ASC(c) sort(ALL(c))
//#define SORT_DESC(c) sort(ALL(c), greater<typeof(*((c).begin()))>())
#define SORT_DESC(c) sort((c).rbegin(),(c).rend())
#define REV(c) reverse((c).begin(), (c).end())
#define SIZE(a) int((a).size())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ROF(i,a,b) for(int i=(b-1);i>=(a);--i)
#define REP(i,n) FOR(i,0,n)
#define PER(i,n) ROF(i,0,n)

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int LARGE_INT = 1e9+100;
const int INF = 2e9+100;
const LL INF_LL = (LL)INF*(LL)INF;
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

int h,w;

bool dfs(int x, int y, VS a){
    a[x][y] = '.';

    if(x==h-1 && y==w-1){
        REP(i,h){
            REP(j,w){
                if(a[i][j] == '#'){
                    return false;
                }
            }
        }
        return true;
    }

    bool f = false;
    VI dx = {1,0};
    VI dy = {0,1};
    REP(i,2){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=h || ny>=w){
            continue;
        }
        if(a[nx][ny] != '#'){
            continue;
        }

        if(dfs(nx,ny,a)){
            f = true;
        }

    }
    return f;
}


void Main()
{
    cin>>h>>w;
    VS a(h);
    REP(i,h){
        cin>>a[i];
    }

    if(dfs(0,0,a)){
        cout<<"Possible"<<endl;
    }
    else{
        cout<<"Impossible"<<endl;
    }


    
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