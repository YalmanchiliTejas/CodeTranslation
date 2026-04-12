#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0),ios::sync_with_stdio(false);
	int rgb=0;
	for(int i=0,t;i<3;++i){
		rgb*=10;
		cin>>t;
		rgb+=t;
	}
	cout<<(rgb%4==0?"YES"s:"NO"s)<<"\n"s;
}