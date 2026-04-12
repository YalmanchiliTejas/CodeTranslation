#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;
int par(int x){
    if(x%2) return -1;
    else return 1;
}
ll dp[3001][3001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    ll a[N];
    rep(i,0,N) cin>>a[i];
    int s;
    s=par(N);
    rep(k,1,N+1){
        rep(i,0,N-k+1){
            if(s*par(k)==1){
                dp[i][i+k]=max(a[i]+dp[i+1][i+k],a[i+k-1]+dp[i][i+k-1]);
            }
            else{
                dp[i][i+k]=min(-a[i]+dp[i+1][i+k],-a[i+k-1]+dp[i][i+k-1]);
            }
        }
    }
    cout <<dp[0][N]<<"\n";
}