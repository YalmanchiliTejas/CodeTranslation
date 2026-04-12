#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
//#define int long long
using namespace std;
typedef pair<int,int>P;
#define fi first
#define se second

signed main(){
	int n;
	cin>>n;
	int a[n];
	r(i,n)cin>>a[i];
	vector<P>v;
	r(i,n){
		v.push_back(P(a[i],i));
	}
	sort(v.begin(),v.end());
	int ans[n];
	r(i,n){
		int x=n/2;
		if(x>i){
			ans[v[i].second]=v[x].first;
		}
		else{
			ans[v[i].second]=v[x-1].first;
		}
	}
	r(i,n)cout<<ans[i]<<endl;
}