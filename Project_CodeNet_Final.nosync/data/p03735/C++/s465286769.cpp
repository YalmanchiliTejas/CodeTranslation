#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

int x[200000], y[200000], n, mx = 0, mn = INF;
int solve1(){
	int a_max = 0, b_min = INF;
	for(int i = 0;i < n;i++){
		int a = min(x[i], y[i]);
		int b = max(x[i], y[i]);
		a_max = max(a_max, a);
		b_min = min(b_min, b);
	}
	return (a_max-mn)*(mx-b_min);
}

typedef pair<int,int> P;
#define fi first
#define se second
priority_queue<int, vector<int>, greater<int> > q;
priority_queue<int> q2;
int solve2(){
	vector<P> v;
	int tmx = 0, tmn = INF;
	for(int i = 0;i < n;i++){
		v.push_back(P(min(x[i], y[i]), i));
		tmx = max(tmx, min(x[i], y[i]));
		q.push(min(x[i], y[i]));
	}
	
	tmn = q.top();
	int res = tmx-tmn;
	sort(v.begin(), v.end());
	//v.push_back(P(max(x[v[0].se], y[v[0].se]), 0));
	
	for(int i = 0;i < n;i++){
		int t1 = max(x[v[i].se], y[v[i].se]);
		int t2 = min(x[v[i].se], y[v[i].se]);
		tmx = max(tmx, t1);
		if(q.top() == t2){
			q.pop();
			q.push(t1);
			tmn = q.top();
		}
		res = min(res, tmx-tmn);
		//printf("%lld %lld\n", tmx, tmn);
	}
	return (mx-mn)*res;
}

signed main(){
	scanf("%lld", &n);
	for(int i = 0;i < n;i++){
		scanf("%lld%lld", &x[i], &y[i]);
		mx = max({mx, x[i], y[i]});
		mn = min({mn, x[i], y[i]});
	}
	int res1 = solve1();
	int res2 = solve2();
	printf("%lld\n", min(res1, res2));
	return 0;
}
