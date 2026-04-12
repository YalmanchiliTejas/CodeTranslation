#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int t[100000],ma=0;
	for(int i=0;i<n;i++){
		cin>>t[i];
		ma=max(ma,t[i]);
	}
	int ans=0;
	vector<int> v;
	for(int i=1;i<=ma;i++)
		if(ma%i==0)v.push_back(i);
	for(int i=0;i<n;i++){
		for(int j=0;j<v.size();j++){
			if(v[j]>=t[i]){
				ans+=v[j]-t[i];
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

