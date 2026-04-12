#include<stack>
#include<map>
#include<set>
#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;
int main(){
	int n,x[200005];
	vector<int> v;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		v.push_back(x[i]);
	}
	sort(v.begin(),v.end());
	int k=n/2;
	for(int tim=1;tim<=n;tim++){
		if(v[n-k-1]>=x[tim]){
			cout<<v[n-k]<<endl;
		}else{
			cout<<v[n-k-1]<<endl;
		}
	}
	return 0;
}