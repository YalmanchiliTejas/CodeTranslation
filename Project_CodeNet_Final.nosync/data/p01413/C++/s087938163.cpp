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
	for(int n,m,w,t;cin>>n>>m>>w>>t && n|m|w|t;){
		map<string,int> f;
		vi ws(m),ps(m);
		rep(i,m){
			string s; cin>>s>>ws[i]>>ps[i];
			f.insert(mp(s,f.size()));
		}
		vi xs(n),ys(n);
		vvi is(n),qs(n);
		rep(i,n){
			int l; cin>>l>>xs[i]>>ys[i];
			is[i].resize(l),qs[i].resize(l);
			rep(j,l){
				string s; cin>>s>>qs[i][j];
				is[i][j]=f[s];
			}
			vector<pii> ps(l);
			rep(j,l) ps[j]=mp(is[i][j],qs[i][j]);
			sort(all(ps));
			rep(j,l) tie(is[i][j],qs[i][j])=ps[j];
		}
		
		vl dp(t+1);
		repi(i,1,1<<n){
			int elapsed=INF; // 全て訪問して帰ってくるのにかかる最小の時間
			vi js;
			rep(j,n) if(i>>j&1) js.push_back(j);
			do{
				int x=0,y=0,tmp=0;
				for(int j:js){
					tmp+=abs(xs[j]-x)+abs(ys[j]-y);
					tie(x,y)=mp(xs[j],ys[j]);
				}
				tmp+=abs(x)+abs(y);
				elapsed=min(elapsed,tmp);
			}while(next_permutation(all(js)));
			
			vl dp2(w+1);
			rep(j,n) if(i>>j&1){
				rep(k,is[j].size()){
					int earn=ps[is[j][k]]-qs[j][k];
					int weight=ws[is[j][k]];
					if(earn<=0) continue;
					repi(l,weight,w+1){
						dp2[l]=max(dp2[l],dp2[l-weight]+earn);
					}
				}
			}
			int earn=*max_element(all(dp2));
			repi(j,elapsed,t+1)
				dp[j]=max(dp[j],dp[j-elapsed]+earn);
		}
		
		cout<<*max_element(all(dp))<<endl;
	}
}