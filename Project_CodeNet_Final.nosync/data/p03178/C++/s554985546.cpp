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
#define INF 0x3f3f3f3f3f3f3f3fLL
#define SIZE 200105
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
 
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
int N;
string str;
int DD;
ll dp[10005][105][3]={0};
	
int main(){
	cin>>str;
	cin>>DD;
	dp[0][0][0]=(ll)0;
	dp[0][0][1]=(ll)1;
	for(int i=0;i<str.size();i++){
		for(int j=0;j<DD;j++){
			for(int k=0;k<=9;k++){
				int ne = (j+DD*9-k)%DD;
				dp[i+1][j][0]=(dp[i+1][j][0] + dp[i][ne][0])%MOD;
				if(k==str[i]-'0')dp[i+1][j][1]=(dp[i+1][j][1] + dp[i][ne][1])%MOD;
				else if(k<str[i]-'0'){
						dp[i+1][j][0]=(dp[i+1][j][0] + dp[i][ne][1])%MOD;
				}
			}
		}
	}
	/*rep(i,str.size()+1){
		rep(j,DD){
			cout<<dp[i][j][0]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	rep(i,str.size()+1){
		rep(j,DD){
			cout<<dp[i][j][1]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;*/
	int m=str.size();
	dp[m][0][0]=(dp[m][0][0]-1+MOD)%MOD;
	cout<<(dp[m][0][0]+dp[m][0][1])%MOD<<endl;
}