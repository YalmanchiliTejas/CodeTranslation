//============================================================================
// Name        : f.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
using namespace std;

int main() {
	int n,s;cin>>n>>s;
	vector<int> a(n);
	vector<long long> v(s,0);
	v[0]=1;
	long long ans=0;
	long long def=998244353;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<=s){
			ans+=(n-i)*v[s-a[i]];
//			cout<<n-i<<' '<<v[s-a[i]]<<endl;
			ans%=def;
		}
		for(int j=s-1;j>=0;j--){
			if(j==0){
				v[j]=i+2;
				break;
			}
			if(j-a[i]>=0){
				v[j]+=v[j-a[i]];
				v[j]%=def;
			}
		}
//		for(int j=0;j<s;j++){
//			cout<<v[j]<<' ';
//		}cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
