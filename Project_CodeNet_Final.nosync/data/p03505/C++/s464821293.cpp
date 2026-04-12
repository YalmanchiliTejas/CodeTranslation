//Author: Lixiang
#include<stdio.h>
#include<iostream>
using namespace std;
struct A{
	long long K,A,B;
	void init(){
		cin>>K>>A>>B;
	}
	void work(){
		K-=A;
		if(K<=0)cout<<1<<endl;
		else
			if(A<=B)puts("-1");
			else{
				long long t=A-B;
				if(K%t==0)cout<<(K/t-1ll)*2ll+3ll<<endl;
				else cout<<(K/t)*2ll+3ll<<endl;
			}
	}
}sol;
int main(){
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	sol.init();
	sol.work();
	return 0;
}
