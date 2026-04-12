#include<bits/stdc++.h>
using namespace std;
int n,a;
vector<pair<int,int> >V;
int ans[234567];
int fix(int k){
	if(k<=(n/2))return V[n/2+1].first;
	else return V[n/2].first;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	V.push_back({-1,-1});
	for(int i=1;i<=n;i++){
		cin>>a;
		V.push_back({a,i});
	}
	sort(V.begin(),V.end());
	for(int i=1;i<=n;i++){
		ans[V[i].second]=fix(i);
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<endl;
	return 0;
}