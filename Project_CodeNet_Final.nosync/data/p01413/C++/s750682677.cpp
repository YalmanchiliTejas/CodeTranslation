#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define isYes(x) printf("%s\n",(x) ? "Yes" : "No")
#define isIn(x,y,h,w) (x >= 0 && x < h && y >= 0 && y < w)

#define int long long
//using ll = long long;
using P = pair<int,int>;

ostream &operator<<(ostream &os,const P &p){ return os << "(" << p.first << "," << p.second << ")"; }

template<class T> T &chmin(T &a,const T &b){ return a = min(a,b); }
template<class T> T &chmax(T &a,const T &b){ return a = max(a,b); }
 
const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000009;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int n,m,w,t,v[10],p[10],l[10],x[10],y[10];
	vector<P> mono[10];
	map<string,int> name_to_ind;
	cin >> n >> m >> w >> t;
	for(int i = 0;i < m;i++){
		string s;
		cin >> s >> v[i] >> p[i];
		name_to_ind[s] = i;
	}
	for(int i = 0;i < n;i++){
		cin >> l[i] >> x[i] >> y[i];
		for(int j = 0;j < l[i];j++){
			string r;
			int q;
			cin >> r >> q;
			mono[i].emplace_back(name_to_ind[r],q);
		}
	}
	vector<P> sina;
	for(int i = 1;i < (1 << n);i++){
		vector<int> vec;
		for(int j = 0;j < n;j++){
			if((i >> j) & 1) vec.push_back(j);
		}
		int mint = INF;
		do{
			int sum = 0,px = 0,py = 0;
			for(int j = 0;j < vec.size();j++){
				sum += abs(px - x[vec[j]]) + abs(py - y[vec[j]]);
				px = x[vec[j]]; py = y[vec[j]];
			}
			sum += abs(x[vec.back()]) + abs(y[vec.back()]);
			chmin(mint,sum);
		}while(next_permutation(all(vec)));
		int dp1[10][10010];
		for(int j = 0;j <= m;j++){
			for(int k = 0;k <= w;k++) dp1[j][k] = -INF;
		}
		dp1[0][0] = 0;
		int rieki[10];
		for(int j = 0;j < m;j++) rieki[j] = -INF;
		for(int j = 0;j < n;j++){
			if(!((i >> j) & 1)) continue;
			for(auto mo : mono[j]){
				chmax(rieki[mo.first],p[mo.first] - mo.second);
			}
		}
		for(int j = 0;j < m;j++){
			for(int k = 0;k <= w;k++){
				if(k - v[j] < 0) dp1[j + 1][k] = dp1[j][k];
				else dp1[j + 1][k] = max(dp1[j][k],dp1[j + 1][k - v[j]] + rieki[j]);
			}
		}
		int kachi = -INF;
		for(int j = 0;j <= w;j++) chmax(kachi,dp1[m][j]);
		sina.emplace_back(mint,kachi);
	}
	int dp2[(1 << n) + 5][10010];
	for(int i = 0;i <= sina.size();i++){
		for(int j = 0;j <= t;j++) dp2[i][j] = -INF;
	}
	dp2[0][0] = 0;
	for(int i = 0;i < sina.size();i++){
		for(int j = 0;j <= t;j++){
			if(j - sina[i].first < 0) dp2[i + 1][j] = dp2[i][j];
			else dp2[i + 1][j] = max(dp2[i][j],dp2[i + 1][j - sina[i].first] + sina[i].second); 
		}
	}
	int ans = -INF;
	for(int i = 0;i <= t;i++) chmax(ans,dp2[sina.size()][i]);
	cout << ans << endl;
}
