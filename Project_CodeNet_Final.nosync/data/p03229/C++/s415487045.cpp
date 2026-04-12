#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<deque>
#include<functional>
#include<iterator>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(n);i>=1;i--)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
const ll MOD=1000000007;
const ll INF=1000000000000000;
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return true;}return false;}
ll maxx(ll x,ll y,ll z){return max(max(x,y),z);}
ll minn(ll x,ll y,ll z){return min(min(x,y),z);}
ll gcd(ll x,ll y){if(x%y==0) return y;else return gcd(y,x%y);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}
ll mid(ll x,ll y,ll z){vector<ll> t(3);t[0]=x;t[1]=y;t[2]=z;sort(all(t));return t[1];}
ll digsz(ll x){if(x==0) return 1;else{ll ans=0;while(x){x/=10;ans++;}return ans;}}
ll digsum(ll x){ll sum=0;while(x){sum+=x%10;x/=10;}return sum;}
ll mod_pow(ll x,ll n,ll mod){ll res=1;while(n>0){if(n&1) res=res*x%mod;x=x*x%mod;n>>=1;}return res;}
vector<ll> pw2(62,1);vector<ll> pw10(19,1);
//2の進数表示の最高位
//例: 7->2 8->3
ll high_order_bit(ll n){ll tmp=1,i=-1;while(tmp<=n){tmp*=2;i++;}if(n==0) return 0;else return i;}
// 6 -> vec[0] [1] [2]
//          0   1   1
//vec[i]:2^iの位
vector<ll> binary_expansion(ll n){vector<ll> B(high_order_bit(n)+1);ll tmp=n;for(ll i=high_order_bit(n);i>=0;i--){B[i]=tmp/pw2[i];tmp%=pw2[i];}return B;}
vector<ll> divisor(ll x){vector<ll> div;for(ll i=1;i*i<=x;i++){if(i*i!=x && x%i==0){div.pb(i);div.pb(x/i);}else if(x%i==0) div.pb(i);}sort(all(div));return div;}
vector<ll> vectorprime(ll x){vector<bool> is_prime(x+1);vector<ll> prime;rep(i,x+1) is_prime[i]=true;is_prime[0]=is_prime[1]=false;for(ll i=2;i<=x;i++){if(is_prime[i]){prime.pb(i);}for(int j=i*2;j<=x;j+=i) is_prime[j]=false;}return prime;}
map<ll,ll> prime_factor(ll x){map<ll,ll> m;ll sq=(ll)sqrt(x) + 1;vector<ll> v_prime=vectorprime(sq);ll tmp=x;rep(i,sz(v_prime)){ll count=0;while(tmp % v_prime[i] == 0){tmp /= v_prime[i];count++;}if(count != 0) m[v_prime[i]]=count;if(tmp==1) break;}if(tmp != 1) m[tmp]=1;return m;}
ll fac[500001],finv[500001],inv[500001],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
void table(){fac[0]=fac[1]=1;finv[0]=finv[1]=1;inv[1]=1;for(ll i=2;i<500001;i++){fac[i]= fac[i-1]*i%MOD;inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;finv[i]=finv[i-1]*inv[i]%MOD;}}
ll dev(long long a,long long b){return (a*inv[b])%MOD;}
ll comb(ll n, ll k){if(n<k) return 0;if(n<0 || k<0) return 0;return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;}
ll perm(ll n,ll k){if(n<k) return 0;if(n<0 || k<0) return 0;return (fac[k]*comb(n,k))%MOD;}


int main(){
    {table();}
    {rep1(i,61) pw2[i]=2*pw2[i-1];}
    {rep1(i,18) pw10[i]=10*pw10[i-1];}
    
    ll N; cin>>N;
    ll ans=0;
    vector<ll> A(N+1,0);
    rep1(i,N) cin>>A[i];
    sort(all(A));
    
    ll t=N-1,pp=(t-1)/2,p=t-pp*2,mm=t/2,m=t-mm*2;
    
    ll tmp=0;
    rep1(i,mm) tmp-=A[i];
    rep1(i,mm+m) tmp-=A[i];
    for(ll i=N;i>N-(pp);i--){
        tmp+=A[i];
    }
    for(ll i=N;i>N-(pp+p);i--){
        tmp+=A[i];
    }
    chmax(ans,tmp);
    
    rep1(i,N) A[i]=pw10[10]-A[i];
    sort(all(A));
    
    tmp=0;
    rep1(i,mm) tmp-=A[i];
    rep1(i,mm+m) tmp-=A[i];
    for(ll i=N;i>N-(pp);i--){
        tmp+=A[i];
    }
    for(ll i=N;i>N-(pp+p);i--){
        tmp+=A[i];
    }
    chmax(ans,tmp);
    
    cout<<ans<<endl;
}
