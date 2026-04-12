#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;


int main(){
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    if(s[0]=='B'){
        for(int i=0;i<m;i++){
            if(s[i]=='B'){s[i]='R';}
            else{s[i]='B';}
        }
    }
    ll l=0;
    while(l<m && s[l]=='R'){l++;}
    if(l==m){
        ll ans=1;
        vector<ll> dp(n,0);
        vector<ll> sum(n,0);
        dp[0]=sum[0]=1;
        for(int i=2;i<n;i++){
            dp[i]=sum[i-2];
            sum[i]=dp[i]+sum[i-1];
            sum[i]%=MOD;
        }
        for(ll i=2;i<=n;i++){
            ans+=sum[n-i]*i%MOD;
        }
        ans%=MOD;
        cout<<ans<<endl;
        return 0;
    }
    if(n&1){cout<<(l==m?1:0)<<endl; return 0;}
    ll mi=E;
    if(l&1){mi=l;}
    else{mi=l+1;}
    for(ll i=l;i<m;i++){
        if(s[i]=='R'){
            ll w=i;
            while(i<m && s[i]=='R'){i++;}
            if(i!=m){
                ll L=i-w;
                if(L&1){mi=min(mi,L);}
            }
        }
    }
    vector<ll> dp(n,0);
    vector<ll> sum(n,0);
    dp[0]=sum[0]=1;
    for(int i=2;i<n;i+=2){
        ll r=sum[i-2];
        ll l=(i-mi-3>=0?sum[i-mi-3]:0LL);
        dp[i]=r-l;
        dp[i]%=MOD;
        sum[i]=sum[i-2]+dp[i];
        sum[i]%=MOD;
        //cout<<dp[i]<<" "<<sum[i]<<endl;
    }
    ll ans=0;
    for(ll i=2;i<=mi+1 && n-i>=0;i++){
        ans+=dp[n-i]*i%MOD;
        ans%=MOD;
    }
    if(l==m){ans++;}
    ans%=MOD;
    if(ans<0){ans+=MOD;}
    cout<<ans<<endl;
    
    
    
    return 0;
}
