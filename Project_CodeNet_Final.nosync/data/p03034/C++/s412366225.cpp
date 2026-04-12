#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <iomanip>
#include <complex>
#include <bitset>
#include <stack>
 
using namespace std;
 
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define repl(i,s,n) for(int i=s; i<=n; ++i)
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define ktya(x) sort(all(x))
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 1e18
#define INFLL 1000000000000000007LL
#define SIZE 200105
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mind(a,b) (a>b?b:a)
#define maxd(a,b) (a>b?a:b)

typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
typedef pair<int,ll> pill; typedef pair<ll,int> plli; 
typedef pair<double, int> pdi;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
typedef complex<double> P;
ll MOD = 1000000007;
//ll MOD=998244353;
typedef ll Weight;
struct Edge {
	int src, dst;
	Weight weight;
};
bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
	e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
int N,Q;
vector<ll>score;

int main(){
	cin>>N;

	rep(i,N){
		ll x;
		cin>>x;
		score.pb(x);
	}
	ll ans=0;
	ll sumA[114514]={0};
	ll sumdif[114514]={0};
	for(int dif=1;dif<=N-1;dif++){
		int res=(N-1)%dif;
		ll now=0;
		for(int cnt=0;cnt<=(N-1-res)/dif;cnt++){
			now+=score[dif*cnt];
			sumdif[cnt]=now;
			//cout<<sumdif[cnt]<<" ";
		}
		//cout<<endl;
		now=0;
		for(int cnt=0;cnt<=(N-1-res)/dif;cnt++){
			now+=score[res+dif*cnt];
			sumA[cnt]=now;
			//cout<<sumA[cnt]<<" ";
		}
		//cout<<endl;
		for(int ind=0;res+ind*dif+dif<N-1;ind++){
			int B=res+ind*dif;
			int A=B+dif;
			ll sum=0;
			if(res!=0){
				sum = sumA[(N-1-res)/dif] -sumA[ind] + sumdif[(N-1-A)/dif];
			}else{
				if(A>N-1-A){
					sum = sumA[(N-1-res)/dif] -sumA[ind] + sumdif[(N-1-A)/dif];
				}
			}
			ans=max(ans,sum);
			//cout<<A<<" "<<B<<" "<<sum<<endl;
		}
	}
	cout<<ans<<endl;
}