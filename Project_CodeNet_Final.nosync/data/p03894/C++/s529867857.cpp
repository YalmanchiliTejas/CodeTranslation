#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3

ll n,q;
ll crt[101010];
bool used[101010];

int main(){
	cin>>n>>q;
  rep(i,n)crt[i]=i;
  used[0]=used[1]=true;
  ll crtpos=0;
  rep(i,q){
    ll a,b;
    cin>>a>>b;
    a--; b--;
    swap(crt[a],crt[b]);
    if(crt[a]==0)crtpos=a;
    if(crt[b]==0)crtpos=b;
    if(crtpos>0)used[crt[crtpos-1]]=true;
    if(crtpos<n-1)used[crt[crtpos+1]]=true;
  }
  ll res=0;
  rep(i,n)if(used[i])res++;
  cout<<res<<endl;
	return 0;
}
