#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define inf (ll)1e9
#define mod (ll)(1e9+7)
#define d(x) cerr<<#x<<"="<<x<<endl;
#define p(x) cout<<(x)<<endl
#define ps(x) cout<<(x);
#define pk(x) cout<<(x)<<" ";
#define pfix(d,x) cout << fixed << setprecision(d) << x << endl;
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define minel(v) *min_element(all(v))
#define minind(v) distance((v).begin(), min_element(all(v)))
#define maxel(v) *max_element(all(v))
#define maxind(v) distance((v).begin(), max_element(all(v)))
#define fi first
#define se second
ll a[51],b[51],c,d,n,m,x,y,z,h,w,k,sum,mi=inf,ma=-inf,ans,s,t,l,r,res,tmp,itr,p,q;
bool flag;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int dx8[8]={1,1,0,-1,-1,-1,0,1},dy8[8]={0,1,1,1,0,-1,-1,-1};
char cha;
string st;
typedef map<ll, ll> imap;
typedef pair<ll, ll> P;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<pair<ll,ll> > VP;


ll burger(ll x, ll l){
   //d(x)d(l)
   if(l==0)return 1;
   if(x<=1)return 0;
   else if(x<2+b[l-1])return burger(x-1, l-1);
   else if(x==2+b[l-1])return a[l-1]+1;
   else if(x<b[l])return a[l-1]+1+burger(x-2-b[l-1], l-1);
   else return a[l];
}

int main(void){
    cin>>n>>x;
    a[0]=1;
    b[0]=1;
    rep(i,1,51)a[i]=2*a[i-1]+1;
    rep(i,1,51)b[i]=2*b[i-1]+3;
    p(burger(x,n));
    return 0;
}
