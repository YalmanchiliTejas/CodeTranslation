#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define int long long
constexpr long long INF = numeric_limits<long long>::max() / 2;
constexpr int MOD = 1000000007;
using Graph = vector<vector<int>>;



signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    int a[n];
    int sum=0;
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
        sum%=MOD;
    }
    int ans=0;
    rep(i,n){
        sum-=a[i];
        while(sum<0)sum+=MOD;
        ans+=a[i]*(sum);
        ans%=MOD;
        while(ans<0)ans+=MOD;
    }
    if(ans<0)ans+=MOD;
    cout<<ans<<endl;




    



}
