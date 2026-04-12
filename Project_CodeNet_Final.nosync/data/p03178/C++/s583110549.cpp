#include <bits/stdc++.h>
using namespace std;
#define __ <<" "<<
#define ___ <<" "
#define bash push_back
#define ALL(x) x.begin(),x.end()
//#define int long long

struct IoSetup {
    IoSetup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout <<fixed<<setprecision(12);
        cerr <<fixed<<setprecision(12);
    }
}IoSetup;

typedef long long ll;
typedef pair < int , int >  pii;
static constexpr const signed int INF = 0x3f3f3f3f;
static constexpr const signed long long LINF = 0x3f3f3f3f3f3f3f3fLL;
static constexpr const signed int SMOD = 1000000007;
static constexpr const signed int NMOD = 998244353;
static constexpr const signed int dx[]={1,0,-1,0,1,1,-1,-1};
static constexpr const signed int dy[]={0,-1,0,1,-1,1,-1,1};

inline bool inside(int x,int y,int w,int h){return (x>=0 && y>=0 && x<w && y<h);}
template<class T>bool chmax(T &a, const T &b){return(a=max(a,b))==b;}
template<class T>bool chmin(T &a, const T &b){return(a=min(a,b))==b;}
inline int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}


int d;
string s;
ll dp[10010][2][200];

signed main() {

    cin >> s >> d;
    int n = s.size();
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < d; j++) {
            
            for(int k = 0; k < 10; k++) {
                int t = j + k;
                dp[i+1][1][t%d] += dp[i][1][j];
                dp[i+1][1][t%d] %= SMOD;
            }
            for(int k = 0; k < s[i]-'0'; k++) {
                int t = j + k;
                dp[i+1][1][t%d] += dp[i][0][j];
                dp[i+1][1][t%d] %= SMOD;
            }
            dp[i+1][0][(j+s[i]-'0')%d] += dp[i][0][j];
            dp[i+1][0][(j+s[i]-'0')%d] %= SMOD;
            
        }
    }

    cout << (dp[n][0][0]+dp[n][1][0]-1+SMOD)%SMOD << endl;
  
    return 0;
}

