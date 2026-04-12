#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

int INF = 1000000007;
int n;
int x[200000], y[200000];

signed main() {
	int i;
	
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		if (x[i] > y[i]) swap(x[i], y[i]);
	}
	
	int S = INF;	//全体の最小値
	int L = -INF;	//全体の最大値
	int Mx = -INF;	//min(x[i], y[i])の最大値
	int Nx = INF;	//max(x[i], y[i])の最小値
	for (i = 0; i < n; i++) S = min(S, min(x[i], y[i]));
	for (i = 0; i < n; i++) L = max(L, max(x[i], y[i]));
	for (i = 0; i < n; i++) Mx = max(Mx, min(x[i], y[i]));
	for (i = 0; i < n; i++) Nx = min(Nx, max(x[i], y[i]));
	int ans = (Mx - S) * (L - Nx);
	
	//あとは、Rmin = S, Rmax = Lとする場合を考えればよい。
	int maxX = -INF;
	int minY = INF;
	for (i = 0; i < n; i++) maxX = max(maxX, x[i]);
	for (i = 0; i < n; i++) minY = min(minY, y[i]);
	
	//簡単のためx_i≦y_iとする。次に頂点x_1,…,x_N,y_1,…,y_N (同じ値ができたら複数生成)を作り、全てのiについてx_i -> y_iと辺を張る。
	//するといい感じに考察ができる。
	//
	//Bmin…青の最小以下の好きな値, Bmax…青の最大以上の好きな値, と置き換える。
	//[Bmin, Bmax]を固定したときに正当か？を考える。Bmax≧maxX, Bmin≦minY
	//が成り立つもとで, 全てのiについて「Bmin≦x_i or Bmax≧y_i」が真⇔正当
	//
	//正当な[Bmin, Bmax]のうち, Bmax - Bminが最小のものを求めよう。とりあえずBminを固定する。
	//すると, x_i < Bminを満たすすべてのiについて、y_i≦Bmaxを満たせばよくなる。
	//そのようなBmaxの最小値は、x_i < Bminを満たすiについてのmax(y_i)と等しい。
	//x_i ≦ Bmin < x_[i+1]のときにBmaxの最小値が変化しないことから、Bminはx_i, y_iのみ想定すればよいことになる。
	//Bmax≧maxX, Bmin≦minYという条件を忘れないように注意する。
	//よって, (x_i, y_i)をx_iが小さい順にソートして、逐次max(y_i)を求めていけばよい。

	
	typedef pair<int, int> P;
	vector<P> vec;
	for (i = 0; i < n; i++) vec.push_back(P(x[i], y[i]));
	sort(vec.begin(), vec.end());
	
	int My = vec[0].second;
	int score = INF;
	for (i = 1; i < n; i++) {
		int Bmin = min(vec[i].first, minY);
		score = min(max(My, maxX) - Bmin, score);
		
		My = max(My, vec[i].second);
	}
	
	ans = min(ans, score * (L - S));
	
	cout << ans << endl;
	return 0;
}