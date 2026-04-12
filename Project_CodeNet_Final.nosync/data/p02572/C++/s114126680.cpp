#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main(){

    ll n;
    cin >> n;

    vector<ll> data(n);
    vector<ll> sum(n);
    rep(i,0,n){
        ll a;
        cin >> a;
        a%= MOD;
        data[i]=a;
        if(i==0){
            sum[i]=a;
        }else{
            sum[i]=(sum[i-1]+a)%MOD;
        }
    }
    ll ans = 0;
    rep(i,0,n){
        ll kake = (sum[n-1]-sum[i]+MOD)%MOD;
        ans += (data[i]%MOD*kake)%MOD;
    }
    ans%=MOD;
    cout<<ans<<endl;
    

    return 0;
}
