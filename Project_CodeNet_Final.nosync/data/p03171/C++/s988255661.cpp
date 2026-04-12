#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
ll dp[3000][3000];
ll a[3000];
ll n;
bool maki[3000][3000];
ll solve(ll x,ll y){
    if(x>y)return 0;
    if(maki[x][y])return dp[x][y];
    maki[x][y]=1;
    return dp[x][y]=(((n-(y-x))&1)?max(solve(x+1,y)+a[x],solve(x,y-1)+a[y]):min(solve(x+1,y)-a[x],solve(x,y-1)-a[y]));
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    memset(maki,0,sizeof(maki));
    for(int i=0;i<n;i++)cin>>a[i];
    cout <<(solve(0,n-1))<<endl;
    return 0;
}
