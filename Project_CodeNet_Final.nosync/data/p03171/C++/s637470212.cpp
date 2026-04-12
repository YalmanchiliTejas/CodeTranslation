#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000 //10^9:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second　//pairの二つ目の要素

int n;
vector<ll> a;
ll dp[3005][3005];

int main(){
    cin>>n;
    a.resize(n);
    rep(i,n) cin>>a[i];
    for(int bit = 0; bit < n; bit++) {
        for(int l = 0; l + bit < n; l++) {
            int r = l + bit;
            if((n+l+r)%2==1){
                dp[l][r]=max(a[l]+dp[l+1][r],a[r]+dp[l][r-1]);
            }
            else{
                dp[l][r]=min(-a[l]+dp[l+1][r],-a[r]+dp[l][r-1]);
            }
        }
    }

    cout<<dp[0][n-1]<<endl;
    return 0;
}