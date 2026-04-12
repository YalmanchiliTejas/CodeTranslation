#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
void solve(){
    int n,k;
    ll ans=0;
    cin>>n>>k;
    if(k==0){
        cout<<1LL*n*n<<endl;
        return;
    }
    rep(b,k+1,n+1){
        for(int j=0;j<n;j+=b){
            if(j+b-1<=n)
                ans+=b-k;
            else ans+=max(0,n-(j+k)+1); 
        }
    }
    cout<<ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}