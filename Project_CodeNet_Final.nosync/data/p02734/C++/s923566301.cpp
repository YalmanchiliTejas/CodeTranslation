#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//const ll MOD=(ll)1e9+7;
const ll MOD=(ll)998244353;
const ll INF=(ll)1e18+10;
const double PI = 2.0*acos(0);

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

ll dp[3010][3010][3];

void solve(int ca){
    memset(dp,0, sizeof(dp));
    int N,S; cin>>N>>S;
    vector<int> a(N);
    for(int i=0;i<N;++i){
        cin>>a[i];
    }
    dp[0][0][0]=1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= S; ++j) {
            //f==0
            (dp[i+1][j][0]+=dp[i][j][0])%=MOD;
            (dp[i+1][j][1]+=dp[i][j][0])%=MOD;
            (dp[i+1][j][2]+=dp[i][j][0])%=MOD;
            //f==1
            (dp[i+1][j][1]+=dp[i][j][1])%=MOD;
            (dp[i+1][j][2]+=dp[i][j][1])%=MOD;
            //f==2
            (dp[i+1][j][2]+=dp[i][j][2])%=MOD;

            if(j+a[i]<=S){
                (dp[i+1][j+a[i]][1]+=dp[i][j][0])%=MOD;
                (dp[i+1][j+a[i]][1]+=dp[i][j][1])%=MOD;
                (dp[i+1][j+a[i]][2]+=dp[i][j][0])%=MOD;
                (dp[i+1][j+a[i]][2]+=dp[i][j][1])%=MOD;
            }

        }
    }
    cout<<dp[N][S][2]<<endl;
}

//#define MULTI
int main() {
#ifdef MULTI
    int N; cin>>N;
    for (int i = 0; i < N; ++i) {
        solve(i+1);
    }
#else
    solve(0);
#endif
    return 0;
}
