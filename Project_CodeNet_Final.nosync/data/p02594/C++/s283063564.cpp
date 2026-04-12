#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define inf 9000000000000000000
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
#define PI 3.14159265359
#define endl '\n'
#define itn int
#define mapint_iterator map<int,int> :: iterator
#define mapll_iterator map<ll,ll> :: iterator
#define setint_iterator set<int> :: iterator
#define setll_iterator set<ll> :: iterator
#define setpint_iterator set<pint> :: iterator
#define setpll_iterator set<pll> :: iterator
#define cout1(a) cout<<a<<endl
#define cout2(a,b) cout<<a<<' '<<b<<endl
#define cout3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define cout4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define vcout(v,i) cout<<v[i].fi<<" "<<v[i].se<<endl
typedef priority_queue<pair<pll,pll>,vector<pair<pll,pll> >,greater<pair<pll,pll> > > pqset;
typedef priority_queue<pll,vector<pll>,greater<pll> > pqset_ll;
#define pb push_back
#define pf push_front
#define fi first
#define mkp make_pair
#define se second
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> os;
typedef tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update> os_pair;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repeat(i,start,n) for(ll i=start;i<n;i++)
#define FileIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
ll ll_max(ll a,ll b,ll c){return max(a,max(b,c));}
int int_max(int a,int b,int c){return max(a,max(b,c));}
ll ll_min(ll a,ll b,ll c){return min(a,min(b,c));}
int int_min(int a,int b,int c){return min(a,min(b,c));}
ll max(int a,ll b){ return max((ll)a,b);}
ll min(int a,ll b){ return min((ll)a,b);}
ll min(ll a,int b){ return min(a,(ll)b);}
ll max(ll a,int b){ return max(a,(ll)b);}
ll power(ll a,ll b){
	if(a==1)
		return 1;
	if(b==0)
		return 1;
	ll c=power(a,b/2);
	ll res=1;
	if(b%2){
		res=c*c;
		if(res>=mod)
			res%=mod;
		res*=a;
	}
	else
		res=c*c;
	if(res>=mod)
		res%=mod;
	return res;
}
ll power(ll a,ll b,ll mod1){
	if(a==1)
		return 1;
	if(b==0)
		return 1;
	ll c=power(a,b/2,mod1);
	ll res=1;
	if(b%2){
		res=c*c;
		if(res>=mod1)
			res%=mod1;
		res*=a;
	}
	else
		res=c*c;
	if(res>=mod1)
		res%=mod1;
	return res;
}
ll modInv(ll a){return power(a,mod-2);}
ll fact[1],inv[1];
void factorial(ll n){
	fact[0]=1;
	for(ll i=1;i<=n;i++){
		fact[i]=fact[i-1]*i;
		if(fact[i]>=mod)
			fact[i]%=mod;
	}
}
void InvFactorial(ll n){
	inv[0]=1;
	for(ll i=1;i<=n;i++)
		inv[i]=modInv(fact[i]);
}
ll ncr(ll n,ll r){
	if(n<r||n<0||r<0)
		return 0;
	ll b=inv[n-r];
	ll c=inv[r];
	ll a=fact[n]*b;
	if(a>=mod)
		a%=mod;
	a*=c;
	if(a>=mod)
		a%=mod;
	return a;
}
bool prime[1];
vector<ll> primes;
void remove_duplicates(vector<pair<int,pint> > &v){sort(v.begin(),v.end());int _size=unique(v.begin(),v.end())-v.begin();v.resize(_size);}
ll gcdll(ll u, ll v){
    ll shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctzll(u | v);
    u >>= __builtin_ctzll(u);
    do {
        v >>= __builtin_ctzll(v);
        if (u > v) {
            ll t = v;
            v = u;
            u = t;
        }  
        v = v - u;
    } while (v != 0);
    return u << shift;
}
unsigned int gcd(unsigned int u, unsigned int v){
    unsigned int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if (u > v) {
            unsigned int t = v;
            v = u;
            u = t;
        }  
        v = v - u;
    } while (v != 0);
    return u << shift;
}
void sieve(ll n){
    memset(prime,true,sizeof(prime));
	prime[1]=false; 
    for (ll p=2;p*p<=n;p++){
        if (prime[p]){
            for (ll i=p*p;i<=n;i+=p)
                prime[i]=false;
        }
    }
    repeat(i,2,n+1)
    	if(prime[i])
    		primes.pb(i);
}
//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
//Use (<<) for multiplication
//Use (>>) for division
// find_by_order -> value at index
// order_of_key -> index of value
// in Floyd-Warshall Algo, k is outer loop
//__gcd(0,0) gives runtime error
//power(a,b) == power(a,b%phi(a)) Fermet's Theorem
//never use "=" operator in compare function
//For checking odd cycles, check bipartite
//Range in iterative segment tree [a,b)
// no of prime numbers in range : (70,19) , (1000,168) , (100000,1229) , (sqrt(10^9),3409) ;
void solve(int countu){
	int x;
	cin>>x;
	if(x>=30)
		cout<<"Yes";
	else
		cout<<"No";
}
int main(){
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	cin.tie(NULL);cout.tie(NULL);cin.sync_with_stdio(0);cout.sync_with_stdio(0);cout<<fixed;
	srand(time(0));
	//cout.precision(9);
	int t=1;
	//cin>>t;
	int countu=1;
	for(int i=1;i<=t;i++){
		solve(countu);
		countu++;
	}
}