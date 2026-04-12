#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define sz(a) int((a).size())
#define F first
#define S second

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
#define travel(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define INDEX(arr,ind)			(lower_bound(all(arr),ind)-arr.begin())

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef pair<int, pii> piii;
typedef pair<ll, pll> plll;
typedef vector<pii> vpii;
typedef vector<piii> vpiii;

inline ll powmod(ll x, ll n, ll _mod){ 
  ll res = 1; 
  while (n){
    if (n & 1)res = (res*x) % _mod; 
    x = (x*x) % _mod; 
    n >>= 1;
    }
    return res; 
  }

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
//******************************************************************//
#define N 100005
int h,w;

int main(){
 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 // freopen("in.txt","r",stdin);
 // freopen("o.txt","w",stdout);

cin>>h>>w;
vpii v;
rep(i,0,h)rep(j,0,w){
	char c;
	cin>>c;
	if(c=='#')v.pb(mp(i,j));
}
sort(all(v));
int n=sz(v);
bool ok=true;
if(v[0]!=mp(0,0) or v[n-1]!=mp(h-1,w-1))ok=0;
rep(i,1,n){
	int x1=v[i-1].F;
	int y1=v[i-1].S;
	int x2=v[i].F;
	int y2=v[i].S;
	if(y1>y2)ok=0;
}
if(ok)cout<<"Possible\n";
else cout<<"Impossible\n";

return 0;
}