#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cerr << #x << ":" << x << "\n"
#define all(x) x.begin(),x.end()

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int ll

const int M=1e9+7;

int mod_pow(int n,int p){
    int ans=1;
    while(p>0){
        if(p%2){
            ans=(ans*n)%M;
        }
        n=(n*n)%M;
        p/=2;
    }
    return ans;
}

void brute(vector<int> &v){
    int ans=0,n=v.size();
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=i+1;j<n;j++){
            cnt++;
            ans=(ans+(v[i]*v[j])%M)%M;
        }
        assert(cnt==n-i-1);
    }
    deb(ans);
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &x:v)cin>>x;
    // brute(v);
    vector<int> suf(n,0);
    suf[n-1]=v[n-1];
    for(int i=n-2;i>=0;i--)suf[i]=(suf[i+1]+v[i])%M;
    int ans=0;
    for(int i=0;i<n-1;i++){
        // int p=mod_pow(v[i],n-i-1);
        int p=v[i];
        int s=suf[i+1];
        p=(p*s)%M;
        ans=(ans+p)%M;
    }
    cout<<ans<<"\n";
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}