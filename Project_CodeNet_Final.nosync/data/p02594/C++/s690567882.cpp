#include <bits/stdc++.h>
#include <bitset>
#include <chrono>
#include <iomanip>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
#define prq priority_queue<ll>;

ll MOD=1000000007;
#define PI 3.1415926535897932384626433832795
#define llMAX 1000000000000000008
#define llMIN -1000000000000000008

#define forx(i,j,n) for(int i=j;i<n;i++)
#define fory(i,j,n) for(int i=j;i>=n;i--)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(false)
#define testcase int t; cin>>t
#define MEM(xx,yy) memset(xx,yy,sizeof(xx))
#define vbs(xx,x) binary_search(all(xx),x)
#define vlb(xx,x) lower_bound(all(xx),x)
#define vub(xx,x) upper_bound(all(xx),x)

#define inpi(xx) scanf("%d",&xx)
#define inpl(xx) scanf("%lld",&xx)
#define inpc(xx) scanf("%c",&xx)
#define inps(xx) scanf("%s",&xx)
#define pri(xx) printf("%d",xx)
#define prl(xx) printf("%lld",xx)
#define prls(xx) printf("%lld ",xx)
#define prle(xx) printf("%lld\n",xx)
#define prc(xx) printf("%c",xx)
#define prs printf(" ")
#define pre printf("\n")
#define flush fflush(stdout)

ll mul(ll mul_1,ll mul_2){ ll mul_t=((mul_1%MOD)*(mul_2%MOD)+MOD)%MOD; return mul_t; }
ll mul3(ll mul_1,ll mul_2,ll mul_3){ ll mul_t=mul(mul(mul_1,mul_2),mul_3)%MOD; return mul_t; }
ll add(ll add_1,ll add_2){ ll add_t=((add_1%MOD)+(add_2%MOD)+MOD+MOD)%MOD; return add_t; }
ll sub(ll sub_1,ll sub_2){ ll sub_r=1e15; ll sub_t=(((sub_1+sub_r)%MOD)-((sub_2+sub_r)%MOD)+sub_r)%MOD; return sub_t; }
ll power(ll x,ll y,ll p){ ll res=1; x=x%p; while(y>0){ if(y&1) res=(res*x)%p; y=y/2; x=(x*x)%p; } return res; } 
ll gcd(ll num1,ll num2){ return (num2?gcd(num2,num1%num2):num1); }
ll lcm(ll num1,ll num2){ return 1LL*((num1*num2)/__gcd(num1,num2)); }
ll countbit(ll num){ return 1LL*(__builtin_popcountll(num)); }
ll setbit(ll num, ll kk){ return 1LL*(num|(1LL<<kk)); }
ll unsetbit(ll num, ll kk){ return 1LL*(num&~(1LL<<kk)); }
ll invertbit(ll num, ll kk){ return 1LL*(num^(1LL<<kk)); }
bool kthbit(ll num, ll kk){ return num&(1LL<<kk); }
ll zerotrail(ll num){ return 1LL*(__builtin_ctzll(num)); }
ll zerobegin(ll num){ return 1LL*(__builtin_clzll(num)); }

clock_t tim;
void showtime(){ tim=clock()-tim; cout<<" ===> "<<(ld)tim/CLOCKS_PER_SEC<<" seconds\n"; }

ll prime[1000005]; 
void sieve(){ //spf
    forx(i,0,1000005) prime[i]=i; 
    for(ll p=2; 1LL*p*p<1000005; p++){ if(prime[p]==p) { for(ll i=1LL*p*p; i<1000005; i+=p) if(prime[i]==i) prime[i]=p; } } 
    return; 
} 
bool isPrime(ll pri){
    if(pri==1||pri==0) return 0;
    if(prime[pri]==pri) return 1;
    return 0;
}
vl alldiv(ll num){
    vl prDiv; for(ll i=1; 1LL*i*i<=num; i++){ if(num%i==0){ prDiv.pb(i); if(i!=(num/i)) prDiv.pb(num/i); } }
    sort(all(prDiv)); return prDiv;
}
vl prdiv(ll num){
    vl prDiv; while(num!=1){ prDiv.pb(prime[num]); ll prtemp=prime[num]; while(num%prtemp==0) num/=prtemp; }
    return prDiv;
}



int main() {
    fastio; //tim=clock();
    //testcase;
    ll t=1;
    forx(T,1,1+t){
        ll n,m,x=0,y=0,cnt=0,ans=0;
        cin>>n;
        if(n>=30) cout<<"Yes\n";
        else cout<<"No\n";
    }
	return 0;
}