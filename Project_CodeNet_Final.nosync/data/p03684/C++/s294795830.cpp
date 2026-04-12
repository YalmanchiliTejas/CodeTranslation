#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> P;
typedef pair<long long, P> PP;

#define MAX_N 100001

long long par[MAX_N]; // 親
long long rankuf[MAX_N]; // 木の深さ
// n要素で初期化
void init(long long n) {
	for (long long i = 0; i < n; i++) {
		par[i] = i;
    rankuf[i] = 0;
	}
}
// 木の根を求める
long long find(long long x) {
	if (par[x] == x) {
		return x;
	} else {
		return par[x] = find(par[x]);
	}
}
// xとyの属する集合を併合
void unite(long long x, long long y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (rankuf[x] < rankuf[y]) {
		par[x] = y;
	} else {
		par[y] = x;
		if (rankuf[x] == rankuf[y]) rankuf[x]++;
	}
}
// xとyが同じ集合に属するか否か
bool same(long long x, long long y) {
	return find(x) == find(y);
}

int main(){
	long long N;
	scanf("%lld",&N);
	init(N);
	vector<long long> x(N-1+1);
	vector<long long> y(N-1+1);
	priority_queue<PP, vector<PP>, greater<PP> > quex, quey;
	for(long long i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&x[i]);
		scanf("%lld",&y[i]);
	}
	vector<P> px(N-1+1);
	vector<P> py(N-1+1);
	for(long long i = 0 ; i <= N-1 ; i++){
		px[i] = P(x[i],i);
		py[i] = P(y[i],i);
	}
	// printf("1\n");
	sort(px.begin(),px.end());
	sort(py.begin(),py.end());
	// printf("1\n");
	for(long long i = 0 ; i < N-1 ; i++){
		quex.push(PP(abs(px[i].first-px[i+1].first), P(px[i].second,px[i+1].second)));
		quey.push(PP(abs(py[i].first-py[i+1].first), P(py[i].second,py[i+1].second)));
	}

	long long res = 0;
// printf("%lld,%lu,%lu,%lld,%lld\n", res, quex.size(), quey.size(),quex.top().first,quey.top().first);
	while (!quex.empty() || !quey.empty()){
		if (quey.empty()) {
			// printf("%lld\n",quex.top().first);
			if (!same(quex.top().second.first,quex.top().second.second)) res += quex.top().first;
			unite(quex.top().second.first,quex.top().second.second);
			quex.pop();
			// printf("1\n");
			// for(long long i = 0 ; i <= N-1 ; i++){
			// 	printf("%lld:%d\n",i,used[i]);
			// }
		} else if (quex.empty()){
			if (!same(quey.top().second.first,quey.top().second.second)) res += quey.top().first;
			unite(quey.top().second.first,quey.top().second.second);
			quey.pop();
			// printf("2\n");
			// for(long long i = 0 ; i <= N-1 ; i++){
			// 	printf("%lld:%d\n",i,used[i]);
			// }
		} else {
			if (quex.top().first < quey.top().first) {
				if (!same(quex.top().second.first,quex.top().second.second)) res += quex.top().first;
				unite(quex.top().second.first,quex.top().second.second);
				quex.pop();
				// printf("3\n");
				// for(long long i = 0 ; i <= N-1 ; i++){
				// 	printf("%lld:%d\n",i,used[i]);
				// }
			} else {
				// printf("%lld,%lld,%lld\n",!used[quey.top().second.first],quey.top().second.first,quey.top().second.second);
				if (!same(quey.top().second.first,quey.top().second.second)) res += quey.top().first;
				unite(quey.top().second.first,quey.top().second.second);
				quey.pop();
				// printf("4\n");
				// for(long long i = 0 ; i <= N-1 ; i++){
				// 	printf("%lld:%d\n",i,used[i]);
				// }
			}
		}
		// printf("%lld,%lu,%lu,%lld,%lld\n", res, quex.size(), quey.size(),quex.top().first,quey.top().first);
	}
	printf("%lld\n", res);
	return 0;
}
