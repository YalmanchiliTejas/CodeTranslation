#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;

#define INF INT_MAX/3

#define MAX_N 1000

int n,m;
bool edge[11][11];
int ord[11];

int main(){
	cin.sync_with_stdio(false);
	cin>>n>>m;
	rep(i,m){
		int a,b;
		cin>>a>>b;
		a--; b--;
		edge[a][b]=edge[b][a]=true;
	}
	ll cnt=0;
	rep(i,n)ord[i]=i;
	do{
		if(ord[0]!=0)continue;
		bool ok=true;
		rep(i,n-1){
			if(!edge[ord[i]][ord[i+1]])ok=false;
		}
		if(ok){
			cnt++;
		}
	}while(next_permutation(ord,ord+n));
	cout<<cnt<<endl;
	return 0;
}
