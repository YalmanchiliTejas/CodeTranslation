#include<bits/stdc++.h>
using namespace std;
int main(){
  	long long n,x,m;
  	map<long long,long long>rec;
	cin>>n>>x>>m;
	vector<long long>s{0};
	long long ans=-1;
	for(int i=0;i<n&&x;++i){
		if(rec.find(x)!=rec.end()){
			long long hn=(n-rec[x])/(i-rec[x]);
			long long res=n-rec[x]-(i-rec[x])*hn;
			ans=hn*(s[i]-s[rec[x]])+s[rec[x]+res];
			break;
		}
		s.push_back(s[s.size()-1]+x); 
		rec[x]=i;
		x=(x*x)%m;
	}
	if(ans==-1){
		ans=s[s.size()-1];
	}
	cout<<ans<<endl;
	return 0;
}