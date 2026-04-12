#include<bits/stdc++.h>

using namespace std;

#define maxn 2000005
#define ll long long int
#define db(x) cout<<#x<<" -> "<<x<<endl
#define db2(x,y) cout<<#x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<endl
#define db3(x,y,z) cout<<#x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<" , "<<#z<<" -> "<<z<<endl
#define prt(x) for(auto it = x.begin(); it!=x.end(); it++){cout<<*it<<" " ;}cout<<endl

namespace NumberTheory{
    const ll mod = (ll)1e9+7;
    ll fact[maxn+5];
    ll inverseFact[maxn+5];
    vector< int > Prime;
    bool vis[maxn+5];
    void seive(){
        for(int i=2; i*i<=maxn; i++){
            if(vis[i]==0){
                for(int j=(2*i); j<=maxn; j+=i){
                    vis[j] = true;
                }
            }
        }
        Prime.push_back(2);
        for(int i=3; i<=maxn; i+=2){
            if(vis[i]==0){
                Prime.push_back(i);
            }
        }
    }

    ll bigmod(ll a, ll n){
        if( n==0 ) { return 1LL; }
        if( n%2==0 ){
            ll ret = bigmod(a,n/2);
            return ( (ret%mod) * (ret%mod) ) % mod;
        }
        else { return ( ( a % mod ) * ( bigmod(a,n-1) % mod ) ) % mod ; }
    }

    ll modInverse(ll a){
        return bigmod(a,mod-2)%mod;
    }

    ll nCr(int n, int r){
        ll ans = (1LL*(fact[n] * inverseFact[r])%mod * inverseFact[n-r]) % mod ;
        return (ans%mod);
    }

    void PreProcess(){
        fact[0] = 1LL;
        for(int i=1; i<=maxn; i++){ fact[i] = (  1LL * fact[i-1] *  i )  % mod ; }
        inverseFact[maxn] = modInverse(fact[maxn]) ;
        for(int x=maxn-1 ; x>=0 ; x--) inverseFact[x] = ( 1LL * inverseFact[x+1] * (x+1) ) % mod ;
    }

    vector< pair< int , int >  > f(int x){
        vector< pair< int , int > > temp;
        for(int i=0; Prime[i]*Prime[i]<=x; i++){
            if(x%Prime[i]==0){
                int cnt = 0;
                while(x%Prime[i]==0){
                    cnt++;
                    x/=Prime[i];
                }
                temp.push_back( make_pair(Prime[i],cnt) );
            }
        }
        if(x>1){
            temp.push_back(make_pair(x,1));
        }
        return temp;
    }
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0);
//    freopen("input.txt","r",stdin);
    using namespace NumberTheory ;
    int n, m , k;
    cin>>n>>m>>k;
    ll ans = 0LL ;
    PreProcess() ;
    for(int i=1; i<=(n-1); i++){
        ans+=( ( (1LL * i * (n-i) ) % mod ) * ( ( m % mod * m % mod ) ) % mod ) % mod  ;
        ans%=mod ;
    }
    for(int i=1; i<=(m-1); i++){
        ans+=( ( (1LL * i * (m-i) ) % mod ) * ( ( n % mod * n % mod ) ) % mod ) % mod ;
        ans%=mod ;
    }
    ans%= mod ;
    ll ret = nCr((1LL * n * m)-2 , k-2);
    ans = ( ans % mod  * ( ret % mod ) ) % mod ;
    cout<<ans<<endl;
    return 0 ;
}
