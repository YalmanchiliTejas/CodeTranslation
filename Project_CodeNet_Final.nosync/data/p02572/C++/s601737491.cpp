#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define full(a) a.begin(),a.end()
#define rfull(a) a.rbegin(),a.rend()

using namespace std;
const double pi=acos(-1.0);
const double pii=2*pi;
const double eps=1e-6;
const long long MOD=1e9+7;

long long pow_mod(long long a, long long b, long long mod){
    long long ans=1;
    a%=mod;
    while(b>0){
        if(b&1){
            ans*=a;
            ans%=mod;
        }
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans;
}

void solve(){
    long long ans=0, sm=0, sqsm=0;
    int n;
    cin>>n;
    vector<long long> a(n,0ll);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        sm+=a[i];
        sqsm+=(a[i]*a[i])%MOD;
    }
    sqsm%=MOD;
    sm%=MOD;
    sm=((sm*sm)%MOD+MOD-sqsm)%MOD;
    cout<<(sm*(pow_mod(2ll,MOD-2,MOD)))%MOD<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}