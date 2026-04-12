#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> pi;
typedef pair<long long, pi> pii;

long long n, c, p[100000];
pii a[100000];
vector<pii> edges;

long long root(long long x){
	return p[x] == -1 ? x : p[x] = root(p[x]);
}

void connect(long long x, long long y){
	p[root(x)] = root(y);
}

bool cmp1(pii a, pii b){
	return a.second.first < b.second.first;
}

bool cmp2(pii a, pii b){
	return a.second.second < b.second.second;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){ cin >> a[i].second.first >> a[i].second.second; a[i].first = i; }
	sort(a, a+n, cmp1);
	for(int i = 1; i < n; i++) edges.push_back(pii(min(abs(a[i].second.first-a[i-1].second.first), abs(a[i].second.second-a[i-1].second.second)), pi(a[i].first, a[i-1].first)));
	sort(a, a+n, cmp2);
	for(int i = 1; i < n; i++) edges.push_back(pii(min(abs(a[i].second.first-a[i-1].second.first), abs(a[i].second.second-a[i-1].second.second)), pi(a[i].first, a[i-1].first)));
	sort(edges.begin(), edges.end());
	memset(p, -1, sizeof(p));
	for(auto &it : edges){
		if(root(it.second.first) != root(it.second.second)){
			c += it.first;
			connect(it.second.first, it.second.second);
		}
	}
	cout << c;
}