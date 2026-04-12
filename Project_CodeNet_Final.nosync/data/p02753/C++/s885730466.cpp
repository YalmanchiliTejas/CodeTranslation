#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define error(x) cerr << #x << " = " << x << endl


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t,n,m,i,j,k,sum=0;
	string a;
	cin>>a;
	set<int> s;
	for(i=0;i<a.size();i++){
		s.insert(a[i]);
	} 
	if(s.size()>1) cout<<"Yes"<<'\n';
	else cout<<"No"<<'\n';
	
	return 0;
}