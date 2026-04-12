#include<iostream>
using namespace std;
long n,x;
long f(long p,long q){
	if(q==0)return 0;
	if(p==0)return 1;
	long m=1LL<<p;
	if(q<2*m-1)return f(p-1,q-1);
	return m+f(p-1,q-2*m+1);
}
int main(){
	cin>>n>>x;
	cout<<f(n,x);
	return 0;
}
