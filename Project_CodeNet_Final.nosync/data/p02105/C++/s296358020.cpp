#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;




int main() {	
	int N;long long int A,B;cin>>N>>A>>B;
	vector<vector<pair<long long int,long long int>>>vs(5,vector<pair<long long int,long long int>>(1,make_pair(0,0)));
	for (int i = 0; i < N; ++i) {
		int t;
		long long int x,y;cin>>t>>x>>y;t--;
		vs[t].push_back(make_pair(x,y));
	}
	sort(vs.begin(), vs.end(), [](const vector<pair<long long int,long long int>>&l, const vector<pair<long long int,long long int>>&r) {return l.size() < r.size(); });
	vector<pair<long long int,long long int>>l;
	vector<pair<long long int,long long int>>r;
	for (auto v1 : vs[0]) {
		for (auto v2 : vs[1]) {
			for (auto v3 : vs[2]) {
				l.emplace_back(v3.first+v1.first+v2.first,v1.second+v2.second+v3.second);
			}
		}
	}
	for (auto v1 : vs[3]) {
		for (auto v2 : vs[4]) {
			r.emplace_back( v1.first + v2.first, v1.second + v2.second );
		}
	}
	sort(l.begin(),l.end());
	sort(r.begin(),r.end(),greater<pair<long long int,long long int>>());
	auto rt=r.begin();
	auto lt=r.begin();
	map<long long int,int>nb;
	bool ok=false;
	for (auto n:l) {
		while (rt != r.end()) {
			if (rt == r.end())break;
			if (rt->first + n.first >=A) {
				nb[rt->second]++;
				rt++;
			}else{
				break;
			}
		}
		while (lt !=r.end()) {
			if (lt == r.end())break;
			if (lt->first + n.first >B) {
				nb[lt->second]--;
				if(nb[lt->second]==0)nb.erase(lt->second);
				lt++;
			}else{
				break;
			}
		}
		auto at=nb.lower_bound(A-n.second);
		auto bt=nb.upper_bound(B-n.second);
		if(at!=bt)ok=true;
	}
	if(ok)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}