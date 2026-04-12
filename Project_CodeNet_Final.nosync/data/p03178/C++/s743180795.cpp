#include <bits/stdc++.h>
using namespace std;

typedef int integer;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define bs binary_search
#define up upper_bound
#define lw lower_bound
#define fs first 
#define sd second 
#define mp make_pair    

#define fore(i,a,b) for(ll i = a; i < b; i++)
#define rfore(i, a, b) for(ll i = a - 1; i >= b; i--)
#define forev(a,b) fore(i,0,b)cout<<a[i]<<" "; 
#define mm(a,b) memset(a , b , sizeof a) 
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())

#define infi  2e9
#define int long long
#define endl '\n'
const ld pi = 3.14159265358979323846;
const ll mod = 1e9+7;
const ll INF = 1e10;
const ll MAXN =1e5;

typedef pair<ll,ll> pll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int a[MAXN];
int d,n;
int dp[MAXN][101][2];

int solve(int pos, int curmod, int bit){
	if(pos==n){
		if((curmod)%d==0)return 1;
		else return 0;
	}
	int &r = dp[pos][curmod][bit];
	if(r!=-1)return r;
	r=0;
	if(bit){
		fore(i,0,10){
			r+=(solve(pos+1,(curmod+i)%d,1)%mod);
		}
	}else{
		fore(i,0,a[pos]+1){
			r+=(solve(pos+1,(curmod+i)%d,(i!=a[pos]))%mod);
		}
	}
	return r;
}

integer main(){
    string s; cin>>s; n=SZ(s);
   	cin>>d;
   	mm(dp,-1);
    fore(i,0,SZ(s))a[i]=s[i]-'0';
    cout<<(solve(0,0,0)-1+mod)%mod;
    return 0;
}


