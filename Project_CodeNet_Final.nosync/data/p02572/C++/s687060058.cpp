#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1001001001;
const long long MOD = 1000000007;
const double EPS = 1e-10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    ll a[n];
    ll c_sum[n+1]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
        c_sum[i+1]=c_sum[i]+a[i];
        c_sum[i+1]%=MOD;
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=(c_sum[n]-c_sum[i+1])*a[i];
        ans%=MOD;
    }
    while(ans<0)ans+=MOD;
    cout<<ans<<endl;
}