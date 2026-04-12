/**
 *   Author:  Wasi Ur Rahman
 *   FROM RMSTU
**/
#include <bits/stdc++.h>
#define ll                      long long
#define boost                   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ticktock                cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n"
#define min3(a,b,c)             min(a,min(b,c))
#define min4(a,b,c,d)           min(d,min3(a,b,c))
#define max3(a,b,c)             max(a,max(b,c))
#define max4(a,b,c,d)           max(d,max3(a,b,c))
#define all(v)                  v.begin(),v.end()
#define revall(v)               v.rbegin(),v.rend()
#define pb                  	push_back
#define eb                      emplace_back
#define mk                      make_pair
#define setbits(x)              __builtin_popcountll(x)
#define zrobits(x)              __builtin_ctzll(x)
#define si(x)               	scanf("%d", &x)
#define sii(x, y)           	scanf("%d %d", &x, &y)
#define siii(x, y, z)       	scanf("%d %d %d", &x, &y, &z)
#define siiii(p,x, y, z)    	scanf("%d %d %d %d",&p, &x, &y, &z)
#define sll(x, y)           	scanf("%lld %lld", &x, &y)
#define slll(x, y, z)       	scanf("%lld %lld %lld", &x, &y, &z)
#define read                	freopen("input.txt","r",stdin)
#define write               	freopen("output.txt","w",stdout)
#define println()          		cout << endl
#define printi(x)           	printf("%d\n")
#define printii(x,y)        	printf("%d %d\n")
#define printiii(x,y,z)     	printf("%d %d %d\n")
#define printl(x)           	printf("%lld\n")
#define printll(x,y)        	printf("%lld %lld\n")
#define printlll(x,y,z)     	printf("%lld %lld %lld\n")
using namespace std;
/*************************************
*          A S S E M B L E           *
**************************************/
bool isPrime(ll n){if(n <= 1)return false;for (ll i = 2; i<=sqrt(n); i++)if (n % i == 0)return false;return true;}
const int mod = 1e9+7;
inline int add(int a,int b){if((a+=b)>=mod)a-=mod;return a;}
inline int dec(int a,int b){if((a-=b)<0)a+=mod;return a;}
ll mult(ll a,ll b){long long t=1ll*a*b;if(t>=mod)t%=mod;return t;}
inline int power(int a,int b){int out=1;while(b){if(b&1)out=mult(out,a);a=mult(a,a);b>>=1;}return out;}
ll fact(ll n){ll res = 1;for(ll i = n;i>=1;i--) res = mult(res,i);return res;}
ll nCr(ll n,ll r){return (fact(n)/(fact(r)*fact(n-r)));}
ll nPr(ll n,ll r){return fact(n)/fact(n-r);}
ll modpow(ll a, ll n, ll mod){ll res=1;while(n>0){if(n&1) res=res*a%mod;a=a*a%mod;n>>=1;}return res;}
bool com(pair<ll,ll> a,pair<ll,ll> b) {if(a.first != b.first)return a.first<b.first;else return (a.second > b.second);}
vector<ll> primes;
vector<pair<ll,ll>> v;
const int N = 10000000;
bool prime[N];
void sieve(){
    memset(prime,1,sizeof(prime));
    primes.pb(2);
    for(ll i = 4;i<=N;i+=2)
        prime[i] = 0;
    for(ll i = 3;i<=N;i+=2){
        if(prime[i]){
            primes.pb(i);
            for(ll j = i*i;j<=N;j+=i*2LL){
                prime[j] = 0;
            }
        }
    }
}
ll NOD (ll n) {
    ll sqrtn = sqrt(n);
    ll res = 1;
    for ( ll i = 0; i < primes.size() && primes[i] <= sqrtn; i++ ) {
        if ( n % primes[i] == 0 ) {
            ll p = 0;
            while ( n % primes[i] == 0 ){
                n /= primes[i];
                p++;
            }
            sqrtn = sqrt ( n );
            p++;
            res *= p;
        }
    }
    if ( n != 1 ) {
        res *= 2;
    }
    return res;
}
/*************************************
*  E N D    G A M E   S T A R T S    *
**************************************/
int main(){
    boost;
    int n,m;
    cin >> n >> m;
    vector<string> v;
    map<int,int> mp,mp1;
    int p = n;
    while(n--){
        string str;
        cin >> str;
        v.pb(str);
    }
    for(int i = 0;i<p;i++){
        int pos = 1;
        for(int j = 0;j<m;j++){
            if(v[i][j] == '#')
                pos = 0;
        }
        if(pos)
            mp[i]++;
    }
    for(int i = 0;i<m;i++){
        int pos = 1;
        for(int j = 0;j<p;j++){
            if(v[j][i] == '#')
                pos = 0;
        }
        if(pos)
            mp1[i]++;
    }
    for(int i = 0;i<p;i++){
        int pos = 0;
        for(int j = 0;j<m;j++){
            if(mp[i] == 0 and mp1[j] == 0){
                cout << v[i][j];
            pos = 1;
            }
        }
        if(pos)
            cout << endl;
    }
    return 0;
}
