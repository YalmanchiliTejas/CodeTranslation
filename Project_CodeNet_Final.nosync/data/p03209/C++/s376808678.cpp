#include<bits/stdc++.h>
using namespace std;
long long height[55]={1};
long long patty[55]={1};
long long f(long long n,long long x){
	if(x==0) return 0;
	if(x>=height[n]) return patty[n];
	
	long long len = height[n];
	if(x>=len/2+1){
		return patty[n-1]+1+f(n-1,x-2-height[n-1]);
	}
	else return f(n-1,x-1);
}
int main(){
	for(int i=1; i<=50; i++){
		height[i] = 3+2*height[i-1];
		patty[i] = 2*patty[i-1]+1;
	}
	long long n,x;
	cin>>n>>x;
	cout<<f(n,x);
}