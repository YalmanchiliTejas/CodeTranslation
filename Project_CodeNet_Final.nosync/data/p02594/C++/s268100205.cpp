#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pii pair<int,int> 
#define pb push_back
#define INF INT_MAX 
#define mod 1000000007ll
#define fi first
#define se second
#define f(i,p,q) for(int i=p;i<q;i++)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pi(a) printf("%d\n",a)
#define psi(a) printf(" %d",a)
#define poi(a) printf("%d",a)
#define sl(a) scanf("%lld",&a)
#define pl(a) printf("%lld\n",a)
#define Nline() printf("\n")
#define sstr(str) scanf("%s",str)
#define pstr(str) printf("%s\n",str)
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define vi vector<int>
#define vvi vector<vi>
#define all(v) (v).begin(),(v).end()
#define SORT(v) sort(all(v))
#define RSORT(v) sort(all(v), greater<int>())
#define ios ios::sync_with_stdio(false); cin.tie(0);cout.tie(NULL);
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
const char nl = '\n';
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  (B) <= (A) && (A) <= (C)
#define AIN(A, B, C) assert(IN(A, B, C))
ll power(ll x, unsigned int y) {ll res = 1;	while (y > 0) { if (y & 1) res = res*x%mod; y = y>>1; x = x*x;} return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
void solve(){
     int n;
     cin>>n;
     if(n>=30)cout<<"Yes";
     else cout<<"No";
}
int main() {
    ios;
	int t=1;
	//cin>>t;
	while(t--)solve();
 
    
}
