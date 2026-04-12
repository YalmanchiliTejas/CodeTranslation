#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long int
#define sd(x) scanf("%lld",&x)
#define inf 1000000000000000000
#define pll pair<ll,ll>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define bits(x) __builtin_popcountll(x)
#define ld long double
#define test() ll test; cin>>test; while(test--)
#define fi first
#define se second


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


inline ll GCD(ll x, ll y) {
    if(x<y) swap(x,y);
    if(x==0) return y;
    if(y==0) return x;
    return GCD(x%y,y);
}

ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}

ll power(ll x, ll n, ll mod) {
    ll res = 1;
    x %= mod;
    while(n) {
        if(n&1) {
            res = ((res*x)%mod+mod)%mod;
        }
        x = ((x*x)%mod+mod)%mod;
        n>>=1;
    }

    return res;
}

const int MAXN = 2e5+5;



int main() {
    fastio;

    ll N,X,M;
    cin>>N>>X>>M;

   
    vector<ll> cnt(M+1,0);
    vector<ll> pre(MAXN,0);
    pre[1] = X;
     pre[0]=0;
    N--;
    ll sum = X;
    cnt[X] = 1;
    for(ll i=2;N>0;i++,N--) {
        X = ((X*X)%M+M)%M;
        if(cnt[X]>0) {
            ll kitne = i-cnt[X];
            ll dum = pre[i-1]-pre[cnt[X]-1];
            ll tim = N/kitne;
            sum += dum*tim;
            ll md = N%kitne;
            dum = pre[cnt[X]-1+md]-pre[cnt[X]-1];
            sum += dum;
            break;
        } else {
            cnt[X] = i;
            pre[i] = pre[i-1]+X;
            sum += X;
        }
    }
    

    cout<<sum<<endl;
}


