#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll int64_t
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};
int dp[2][111111][111];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    dp[0][0][0] = 1;
    string s;cin>>s;
    int n,d;
    cin>>d;
    n = s.size();
    REP(i,n){
        REP(j,10){
            REP(k,d){
                add(dp[1][i+1][(k+j)%d],dp[1][i][k]);
                if(j>s[i]-'0') continue;
                else if(j < s[i] - '0') add(dp[1][i+1][(k+j)%d],dp[0][i][k]);
                else add(dp[0][i+1][(k+j)%d],dp[0][i][k]);
            }
        }
    }
    cout<<(dp[0][n][0]+dp[1][n][0]-1+MOD)%MOD<<endl;
}