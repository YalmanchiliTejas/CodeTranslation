#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define pd pair<double,double>
#define ld long double
#define pld pair<ld,ld>
#define lg length()
#define sz size()
#define pb push_back
#define INF 1000000005
#define LINF 1000000000000000005

string k;

int d,s;

ll dp[10005][105],mod=1e9+7;

int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> k >> d;
    for(int i=1;i<=k.lg;i++){
        for(int j=0;j<d;j++){
            for(int t=0;t<=9;t++){
                dp[i][j]+=dp[i-1][((j-t)%d+d)%d];
                if(t<k[i-1]-'0' && (s+t)%d==j) dp[i][j]++;
            }
            dp[i][j]%=mod;
        }
        s+=k[i-1]-'0'; s%=d;
    }
    if(s%d==0) dp[k.lg][0]++;
    cout << (dp[k.lg][0]-1+mod)%mod << '\n';
}
