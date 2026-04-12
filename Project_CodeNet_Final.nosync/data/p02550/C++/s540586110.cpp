#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x,m,sum;
vector<int>v;
set<int>s;
signed main(){
	cin>>n>>x>>m;
	for(;!s.count(x);x=x*x%m)
		s.insert(x),v.push_back(x);
	if(n<=v.size()){
		for(int i=0;i<n;i++)sum+=v[i];
		cout<<sum;return 0;
	}
	int t=v[v.size()-1]*v[v.size()-1]%m,p=0;
	for(int i=0;i<v.size();i++)
	    if(v[i]==t){p=i;break;}
	for(int i=p;i<v.size();i++)sum+=v[i];
	sum*=(n-p)/(v.size()-p);
	n=(n-p)%(v.size()-p)+p;
	for(int i=0;i<n;i++)sum+=v[i];
	cout<<sum;
}
