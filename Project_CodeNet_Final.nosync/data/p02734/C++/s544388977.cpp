#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
const ll MOD2=(ll)998244353;
const ll INF=(ll)1e18+10;
const double PI=acos(-1);

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

ll dp[3010][6300][3];

int main() {
    int N,S; cin>>N>>S;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin>>a[i];
    }
    memset(dp,0, sizeof(dp));
    dp[0][0][0]=1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= S; ++j) {
            (dp[i+1][j][0]+=dp[i][j][0])%=MOD2;
            (dp[i+1][j+a[i]][1]+=dp[i][j][0]*(i+1))%=MOD2;
            (dp[i+1][j+a[i]][2]+=dp[i][j][0]*(i+1)*(N-i))%=MOD2;

            (dp[i+1][j][1]+=dp[i][j][1])%=MOD2;
            (dp[i+1][j+a[i]][1]+=dp[i][j][1])%=MOD2;
            (dp[i+1][j+a[i]][2]+=dp[i][j][1]*(N-i))%=MOD2;

            (dp[i+1][j][2]+=dp[i][j][2])%=MOD2;

        }
    }
    cout<<dp[N][S][2]<<endl;
    return 0;
}
