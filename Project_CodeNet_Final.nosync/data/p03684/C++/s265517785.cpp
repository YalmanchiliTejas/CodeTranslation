#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
static const int MAX_N = 100000;
struct edge{int from, to; ll cost;};

int N;
int x[MAX_N], y[MAX_N];

P s1[MAX_N], s2[MAX_N];
vector<edge> es;

int par[MAX_N];
int rank_[MAX_N];
void init_union_find(int n){
	for(int i = 0; i < n; i++){
		par[i] = i;
		rank_[i] = 0;
	}
}
int find(int x){
	if(par[x] == x){
		return x;
	}else{
		return par[x] = find(par[x]);
	}
}
void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(rank_[x] < rank_[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(rank_[x] == rank_[y]) rank_[x]++;
	}
}
bool same(int x, int y){
	return find(x) == find(y);
}
bool comp(const edge& e1, const edge& e2){
	return e1.cost < e2.cost;
}

ll kruskal(){
	sort(es.begin(), es.end(), comp);
	init_union_find(N);
	ll res = 0;
	for(int i = 0; i < es.size(); i++){
		edge e = es[i];
		if(!same(e.from, e.to)){
			unite(e.from, e.to);
			res += e.cost;
		}
	}
	return res;
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> x[i] >> y[i];
	}
	for(int i = 0; i < N; i++){
		s1[i].first = x[i]; s1[i].second = i;
		s2[i].first = y[i]; s2[i].second = i;
	}
	sort(s1, s1 + N);
	sort(s2, s2 + N);
	for(int i = 0; i < N - 1; i++){
		es.push_back((edge){s1[i].second, s1[i + 1].second, abs(s1[i].first - s1[i + 1].first)});
		es.push_back((edge){s1[i + 1].second, s1[i].second, abs(s1[i].first - s1[i + 1].first)});
		es.push_back((edge){s2[i].second, s2[i + 1].second, abs(s2[i].first - s2[i + 1].first)});
		es.push_back((edge){s2[i + 1].second, s2[i].second, abs(s2[i].first - s2[i + 1].first)});
	}
	cout << kruskal() << endl;
	return 0;
}
