#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	long long k,a,b;
	cin>>k>>a>>b;
	if(a>=k){
		cout<<1<<endl;
		return 0;
	}
	if(a<=b){
		cout<<-1<<endl;
		return 0;
	}
	cout<<((k-a)/(a-b)+((k-a)%(a-b)>=1))*2+1<<endl;
	return 0;
}
