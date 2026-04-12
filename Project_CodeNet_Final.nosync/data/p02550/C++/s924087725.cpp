#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define int long long int
#define all(x) (x).begin(), (x).end()
#define removeDuplicates(a) a.resize(unique(all(a))-a.begin())
#define endl '\n'

void solve(){
	int n,x,m;
	cin>>n>>x>>m;
	vector<int>pos(m,-1);
	vector<int>val;
	int curr=x;
	int p=0;
	while(p<n){
		if(pos[curr]!=-1){
			p=pos[curr];
			break;
		}
		pos[curr]=p;
		p++;
		val.push_back(curr);
		curr=(curr*curr)%m;
	}
	int ans=0;
	for(int i=0;i<p;i++){
		ans+=val[i];
	}
	if(p<val.size()){
		int total=(val.size()-p);
		int mul=(n-p)/total;
		int rem=(n-p)%total;
		for(int i=p;i<val.size();i++){
			ans+=(mul+(rem>0?1:0))*val[i];
			rem--;
		}
	}
	cout<<ans<<endl;
}

int32_t main(){

	//remove for interactive problems
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	solve();
	cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";

	return 0;
}