#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<random>
#include<array>
#include<cassert>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())


int x[100000], y[100000];
bool used[100000];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;
	rep(i, n)cin >> x[i] >> y[i];
	set<pair<int,int>> xg,yg;
	set<pair<int, int>, greater<pair<int,int>>> xl, yl;

	rep(i, n){
		xg.emplace(x[i],i);
		yg.emplace(y[i], i);
		xl.emplace(x[i], i);
		yl.emplace(y[i], i);
	}

	long long ans=0;
	priority_queue<pair<int, int>, vector<pair<int,int>> ,greater<pair<int, int>>> pq;
	pq.emplace(0, 0);
	rep(i,n){
		auto p = pq.top();
		pq.pop();
		while (used[p.second]){
			p = pq.top();
			pq.pop();
		}
		used[p.second] = true;
		xg.erase(make_pair(x[p.second], p.second));
		yg.erase(make_pair(y[p.second], p.second));
		xl.erase(make_pair(x[p.second], p.second));
		yl.erase(make_pair(y[p.second], p.second));
		ans += p.first;

		auto it1 = xg.lower_bound(make_pair(x[p.second], 0));
		if (it1 != xg.end()){
			pq.emplace(min(abs(x[p.second] - x[it1->second]), abs(y[p.second] - y[it1->second])), it1->second);
		}
		auto it2 = yg.lower_bound(make_pair(y[p.second], 0));
		if (it2 != yg.end()){
			pq.emplace(min(abs(x[p.second] - x[it2->second]), abs(y[p.second] - y[it2->second])), it2->second);
		}
		auto it3 = xl.lower_bound(make_pair(x[p.second], INF));
		if (it3 != xl.end()){
			pq.emplace(min(abs(x[p.second] - x[it3->second]), abs(y[p.second] - y[it3->second])), it3->second);
		}
		auto it4 = yl.lower_bound(make_pair(y[p.second], INF));
		if (it4 != yl.end()){
			pq.emplace(min(abs(x[p.second] - x[it4->second]), abs(y[p.second] - y[it4->second])), it4->second);
		}

	}
	cout<<ans<<endl;

	return 0;
}