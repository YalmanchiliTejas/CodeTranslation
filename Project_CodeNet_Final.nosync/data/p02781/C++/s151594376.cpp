//============================================================================
// Name        : e.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string ss;cin>>ss;
	vector<int> n;
	for(int i=0;i<ss.size();i++){
		n.push_back(ss[i]-'0');
	}
	int k;cin>>k;
	vector<int> v1(101),v2(101),v3(101);
	long long ans=0;
	v1[1]=9;
	for(int i=2;i<=100;i++){
		v1[i]=9;
		v2[i]=9*(i-1)*9;
		v3[i]=9*9*9*(i-2)*(i-1)/2;
	}
	int dig=n.size();
	int s,t;
	s=t=0;
	for(int i=1;i<dig;i++){
		if(n[i]){
			s=i;
			break;
		}
	}
	for(int i=s+1;i<dig;i++){
		if(n[i]){
			t=i;
			break;
		}
	}
//	cout<<s<<' '<<t<<endl;
	if(k==1){
		ans=(n[0]);
		for(int i=1;i<dig;i++){
			ans+=v1[i];
		}
	}else if(k==2){
		if(s==0){
			ans=(n[0]-1)*(dig-1)*9;
			ans+=(dig-1)*(dig-2)/2*9*9;
			cout<<ans<<endl;
			return 0;
		}
//		ans=n[s];
//		ans+=(n[0]-1)*9;
//		ans+=n[0]*(dig-1-s)*9;
//		ans+=9*(dig-1-s)*9;
		ans=n[s];
		ans+=(dig-1-s)*9;
		ans+=(n[0]-1)*(dig-1)*9;
		ans+=(dig-1)*(dig-2)/2*9*9;
//		cout<<n[s]<<' '<<(dig-1-s)*9<<' '<<(n[0]-1)*(dig-1)*9<<endl;
	}else{
		if(s==0){
			ans=(n[0]-1)*(dig-1)*(dig-2)/2*9*9;
			ans+=(dig-1)*(dig-2)*(dig-3)/6*9*9*9;
		}
		if(t==0){
			ans=(n[s]-1)*(dig-1-s)*9;
			ans+=(dig-1-s)*(dig-2-s)/2*9*9;
			ans+=(n[0]-1)*9*9*(dig-1)*(dig-2)/2;
			ans+=(dig-1)*(dig-2)*(dig-3)/6*9*9*9;
			cout<<ans<<endl;
			return 0;
		}

//		ans=n[t];
//		ans+=(n[s]-1)*9;
//		ans+=(n[0]-1)*9*9;
//		ans+=n[s]*(dig-1-t)*9;
//		ans+=(n[0]-1)*9*(dig-1-t)*9;
//		ans+=n[0]*
		ans+=n[t];
		ans+=(dig-1-t)*9;
		ans+=(n[s]-1)*(dig-1-s)*9;
		ans+=(dig-1-s)*(dig-2-s)/2*9*9;
		ans+=(n[0]-1)*9*9*(dig-1)*(dig-2)/2;
		ans+=(dig-1)*(dig-2)*(dig-3)/6*9*9*9;
	}
	cout<<ans<<endl;
	return 0;
}