/*
 * coder: @SumitRaut
 */
#include <iostream>

using namespace std;
#define ll long long
ll mod=1e9+7;
inline void solve() {
    int n;
    cin>>n;
    ll ans=0,pre,tmp;
    cin>>pre;
    while(--n) {
        cin>>tmp;
        ans=(ans+pre*tmp%mod)%mod;
        pre=(pre+tmp)%mod;
    }
    cout<<ans<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //freopen("int.txt","r",stdin);
    #endif
    // int t; cin>>t; while(t--)
        solve();
    return 0;
}
