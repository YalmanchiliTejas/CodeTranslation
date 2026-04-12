#include<bits/stdc++.h>
#define INFTY 10000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using P = pair<int,int>;
typedef long long int ll;
const int MOD=1000000007;
const int di[4] = {-1,0,1,0};
const int dj[4] = {0,-1,0,1};

int main(){
    int n;cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    ll ans = 0,sum = 0;
    for(int i = n-1;i>0;i--){
        sum =(sum + a[i])%MOD;
        ans = (ans + a[i-1]*sum)%MOD;
        ans%=MOD;
    }
cout<<ans<<endl;

    return 0;
}