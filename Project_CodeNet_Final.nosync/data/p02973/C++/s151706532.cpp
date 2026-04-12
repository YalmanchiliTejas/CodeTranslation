//------------------------------------------
// C++ templete 
//------------------------------------------
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using ll = long long;

#define endl "\n"

//typedef
//------------------------------------------
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<PII> VP;

//REPEAT
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//container util
//------------------------------------------
#define pb push_back
#define paired make_pair
#define ALL(a) (a).begin(),(a).end()
#define PRINT(V) for (auto v : (V)) cout << v << " "
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())

//constant
//------------------------------------------
const int MOD = 1000000007;
const int INF = 1061109567;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

//debug
//------------------------------------------
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

//最大公約数と最小公倍数
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    int n_c = 0;
    VI C(N, -1);
     
    REP(i,N)
    {
        int a; cin >> a;
        if (i==0)
        {
            C[0] = a; n_c++;
            continue;
        }
        
        else if (C[n_c-1] >= a)
        {
            C[n_c] = a;
            n_c++;
            continue;
        } 
        REP(j,n_c)
        {
            if (C[j] < a)
            {
                C[j] = a;
                break;
            }
        }
    }
    cout << n_c << endl;
  
    return 0;
}

