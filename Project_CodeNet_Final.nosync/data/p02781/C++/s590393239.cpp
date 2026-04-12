#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (ll i = a; i < b; i++)
#define REP(i,b) FOR(i,0,b)
#define RFOR(i,a,b) for (ll i = a-1; i >= b; i--)
#define RREP(i,a) RFOR(i,a,0)
#define REPALL(i,x) for (ll i = 0; i < x.size(); i++)
#define RREPALL(i,x) for (ll i = x.size()-1; i >= 0; i--)
#define REPITR(itr,x) for (auto itr = (x).begin(); itr != (x).end(); itr++)
#define ALL(x) (x).begin(), (x).end()
#define SORT(x) sort(ALL(x))
#define MIN_ELEMENT(x) min_element(ALL(x))
#define MAX_ELEMENT(x) max_element(ALL(x))
#define COUNT(x,num) count(ALL(x), num)
#define MEMSET(x,val) memset(x, val, sizeof(x))
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define debug(x) cerr<<__LINE__<<": "<<(#x)<<" = "<<(x)<<endl;
void YES(bool flag) {cout<<(flag ? "YES" : "NO")<<endl;}
void Yes(bool flag) {cout<<(flag ? "Yes" : "No")<<endl;}
void yes(bool flag) {cout<<(flag ? "yes" : "no")<<endl;}
#define e1 first
#define e2 second
#define nextline putchar('\n')
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<ll> VLL;
typedef vector<vector<ll>> VVLL;
const int INF = 1e7;
const ll MOD = 1e9 + 7;

string n;
int k;
VVI dp0(100, VI(100, 0)), dp1(100, VI(100, 0));

int main()
{
    cin>>n>>k;
    dp0.resize(n.size() + 1);
    dp1.resize(n.size() + 1);

    if (n.size() < k) {
        cout<<0<<endl;
        exit(0);
    }

    dp0[0][0] = 1;
    dp0[0][1] = n[0] - '1';
    dp1[0][1] = 1;
    REP(i,n.size() - 1) {
        int tmp = n[i+1] - '0';
        REP(j,k+1) {
            if (tmp == 0) {
                dp0[i+1][j+1] += dp0[i][j] * 9;
                dp0[i+1][j] += dp0[i][j];
                dp1[i+1][j] += dp1[i][j];
            } else {
                dp0[i+1][j+1] += dp0[i][j] * 9 + dp1[i][j] * (tmp - 1);
                dp0[i+1][j] += dp0[i][j] + dp1[i][j];
                dp1[i+1][j+1] += dp1[i][j];
            }
        }
    }
    /* REP(i,n.size()) {
        REP(j, k+1) {
            cout<<dp0[i][j]<<"_"<<dp1[i][j]<<"    ";
        }
        nextline;
    }
    cout<<dp0[n.size()-1][k]<<endl;
    cout<<dp1[n.size()-1][k]<<endl; */
    cout<<dp0[n.size()-1][k] + dp1[n.size()-1][k]<<endl;

    return 0;
}
