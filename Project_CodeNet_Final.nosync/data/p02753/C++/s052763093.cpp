#include <bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(false)
#define pb push_back
#define pqueue priority_queue
#define fi first
#define se second
#define ls rt<<1
#define rs rt<<1|1
#define sz(x) (int)(x).size()
#define dbg(x) cout<<#x<<" --- "<<x<<endl
#define mst(x,a) memset(x,a,sizeof(x))
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
ll qpow(ll a,ll b,ll m){ ll r=1;a%=m;for(;b;b>>=1){if(b&1)r=r*a%m;a=a*a%m;}return r; }
const int inf=0x7fffffff;

int main(){
	io;
	string s;cin>>s;
	if(s[0]==s[1]&&s[0]==s[2])cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}