#include <bits/stdc++.h>
using namespace std;

#define dump(n) cout<<"# "<<#n<<'='<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define all(c) begin(c),end(c)
#define mp make_pair
#define mt make_tuple

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;

const int INF=1e9;
const int MOD=1e9+7;
const double EPS=1e-9;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& a){
	os<<'[';
	rep(i,a.size()) os<<(i?" ":"")<<a[i];
	return os<<']';
}

int main()
{
	for(int n;cin>>n && n;){
		vi hs(n),ws(n);
		rep(i,n) cin>>hs[i]>>ws[i];
		vs grid(4);
		rep(i,4) cin>>grid[i];
		
		queue<pii> q;
		q.emplace(0,0);
		vi vis(1<<16);
		while(q.size()){
			int bit,turn; tie(bit,turn)=q.front(); q.pop();
			if(bit==(1<<16)-1){
				cout<<turn<<endl;
				break;
			}
			if(vis[bit]) continue;
			vis[bit]=1;
			
			rep(k,n){
				repi(i0,-hs[k]+1,4) repi(j0,-ws[k]+1,4){
					bool ok=true;
					char color='?';
					int mask=0;
					rep(i,hs[k]) rep(j,ws[k]){
						if(i0+i<0 || 4<=i0+i || j0+j<0 || 4<=j0+j) continue;
						mask|=1<<(i0+i)*4+(j0+j);
						if(bit>>(i0+i)*4+(j0+j)&1) continue;
						if(color=='?') color=grid[i0+i][j0+j];
						if(grid[i0+i][j0+j]!=color) ok=false;
					}
					if(ok && !vis[bit|mask]) q.emplace(bit|mask,turn+1);
				}
			}
		}
	}
}