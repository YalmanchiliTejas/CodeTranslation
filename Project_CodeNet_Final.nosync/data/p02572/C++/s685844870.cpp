#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lundi ios_base::sync_with_stdio(false); cin.tie(NULL);

const int M = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> suffix(n, 0);
    for(int i=0;i<n;i++) cin>>v[i];
    int sm = 0;
    int ans = 0;
    for(int i=n-2;i>=0;i--){
        sm += v[i+1];
        ans += v[i]*sm;
        ans %= M;
        sm %= M;
    }
    cout<<ans<<endl;
}

signed main(){
    // lundi;
    int t=1;
    // cin>>t;
    while(t--) solve();
}