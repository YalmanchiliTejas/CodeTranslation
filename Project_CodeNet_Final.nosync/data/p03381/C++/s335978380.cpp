#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	vector<pair<int,int>> v(n);
	for(int i=0;i<n;++i){
	       cin>>v[i].first;
	       v[i].second=i;
	}
	sort(v.begin(), v.end());
	vector<int> ans(n);
	for(int i=0;i<n;++i){
		ans[v[i].second]=i<n/2?v[n/2].first:v[n/2-1].first;
	}
	for(auto i: ans) cout<<i<<'\n';
}
