#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
const int MOD=1e9+7;
const int INF=1e18;


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    int n;cin>>n;
    vi v(n+1),suf(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    suf=v;
    for(int i=n-1;i>=1;i--){
        suf[i]+=suf[i+1];
        suf[i]%=MOD;
    }
    
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=v[i]*(i+1<=n?suf[i+1]:0)%MOD;
        sum%=MOD;
    }
    cout<<sum;
    
}