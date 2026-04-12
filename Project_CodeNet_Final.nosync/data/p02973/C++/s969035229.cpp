#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
//using namespace __gnu_pbds;
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using ll=long long;
using ld=long double;
#define inf 1<<30  
const ll infll=1ll*inf*inf;
#define mode 998244353
#define mod 1000000007
const long double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define pb push_back
#define mp make_pair
#define ub upper_bound 
#define lb lower_bound 
#define far(i,a,b) for (ll i = a; i <= b; i++)
#define rev(i,a,b) for (ll i = a; i >= b; i--)
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define sz(a) ll((a).size())
#define ftr(c,i) for(auto i = begin(c); i != end(c); i++)
#define rtr(c,i) for(auto i = rbegin(c); i != rend(c); i++)
#define pre(c,x) ((c).find(x) != (c).end())
#define cpre(c,x) (find(all(c),x) != (c).end())
#define mii map<int,int>
#define mll map<ll,ll>
#define vs vector<string>
#define vi vector<int>
#define vl vector<ll>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vii vector<pii >
#define vll vector<pll >
#define vvl vector<vector<ll> >
#define vvi vector< vector<int > >
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout <<(ll)(it-arr.begin()) << ')' <<  *it << ' '; cout << endl;
#define printii(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << it->ff<<' '<<it->ss << endl; cout << endl;
#define mems(a,i) memset(a,i,sizeof(a));
#define MID(i,j) ((i)+(j))/2
#define nl '\n' 
//#define nl endl 
#define lcm(a,b) a/gcd(a,b)*b;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll max(ll a,ll b) {return (a>b? a:b);}
ll min(ll a,ll b) {return (a>b? b:a);}
ll gcd(ll a,ll b) {return (b==0)? a:gcd(b,a%b); }
ll gcd(ll a,ll b,ll & x,ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
ll modinv(ll a,ll b){
	ll x,y;
	gcd(a, b, x, y);
	return (x%b + b)%b;
}
ll ceiling(ll a,ll b){ 
        if(a%b==0) return a/b;
        else return a/b+1;
}
ll bpow(ll a,ll b,ll m){
	a%=m;
	ll res=1;
	while(b>0){
		if(b&1) res=(res*a)%m;
		b>>=1;
		a=a*a%m;
	}
	return res;
}
vvl mat_mul(vvl mat1,vvl mat2,ll mod1){
        vvl res(sz(mat1),vl(sz(mat2[0]),0));
        far(i,0,sz(mat1)-1){
                far(j,0,sz(mat2[0])-1){
                        far(k,0,sz(mat1[0])-1){
                                res[i][j]=(res[i][j]+(mat1[i][k]*mat2[k][j])%mod1)%mod1;          
                        }   
        }   
        }   
        return res;
}

vvl mat_exp(vvl mat,ll p,ll mod1){ 
        vvl res(sz(mat),vl(sz(mat[0]),0));
        far(i,0,sz(mat)-1) res[i][i]=1;
        while(p>0){
                if(p&1) res=mat_mul(res,mat,mod1);   
                mat=mat_mul(mat,mat,mod1);
                p>>=1;
        }   
        return res;
}
//find_by_order()  // order_of_key()
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> o_s;

const int N=2*100000+5;
ll n,m,t,q,k,x,y,z,w,ans;
int a[N];
multiset<int> rk;
int main(){
	fio;
	cin >> n;
	far(i,1,n) cin >> a[i];
	rk.insert(a[1]);
	far(i,2,n){
		auto it=rk.lb(a[i]);
		if(it==rk.begin()) rk.insert(a[i]);
		else{
			it--;
			rk.erase(it);
			rk.insert(a[i]);
		}
	}
	cout << sz(rk) << nl;

}
