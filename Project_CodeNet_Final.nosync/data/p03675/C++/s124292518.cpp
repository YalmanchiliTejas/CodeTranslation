#include <bits/stdc++.h>
using namespace std;

int main(){
	static int n;
	static int a[200010];
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	
	vector<int> v[2];
	for(int i=0;i<n;i++){
		v[i&1].push_back(a[i]);
	}
	int t=(n-1)&1, t_=1-t;
	reverse(v[t].begin(),v[t].end());
	v[t].insert(v[t].end(),v[t_].begin(),v[t_].end());
	for(int i=0;i<v[t].size();i++){
		printf("%d%c",v[t][i],(i+1==v[t].size())?'\n':' ');
	}
}