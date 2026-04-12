#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,x,m;
	cin>>n>>x>>m;
	set<long long> s;
	vector<long long> v;
	while(1){
		if(s.find(x)!=s.end())break;
		s.insert(x);
		v.push_back(x);
		x=x*x;
		x%=m;
	}
	long long cnt=0;
	if(v.size()>=n){
		for(int i=0;i<n;i++){
			cnt+=v[i];
		}
		cout<<cnt<<endl;
		return 0;
	}
	int j;
	for(int i=0;i<v.size();i++){
		if(v[i]==x){
			j=i;
			break;
		}
		cnt+=v[i];
	}
	long long ans=0;
	if(j==0){
		for(int i=0;i<v.size();i++){
			ans+=v[i];
		}
		ans=ans*(n/(long long)(v.size()));
		int tmp=n%(long long)(v.size()); 
		if(tmp!=0){
			for(int i=0;i<tmp;i++){
				ans+=v[i];
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=j;i<v.size();i++){
		ans+=v[i];
	}
//	cout<<1;
	ans=ans*((n-(long long)(j))/(long long)(v.size()-j));
	long long k=(n-(long long)(j))%(long long)(v.size()-j);
//	cout<<1;
	if(k>0){
		for(int i=j;i<j+k;i++){
			ans+=v[i];
		}
	}
	cout<<cnt+ans<<endl;
	return 0;
}