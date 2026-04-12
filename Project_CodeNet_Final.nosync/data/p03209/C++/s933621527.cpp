#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
const int  N = 55+66;
#define  LL long long
LL len[N];
LL P[N];

LL f(LL n,LL x)
{
	if(x==0) return 0;
	if(n==0) return 1;
	else if(n!=0&&x==1){
		return 0;
	}else if(x<1+len[n-1]){
		return f(n-1,x-1);
	}else if(x==1+len[n-1]){
		return P[n-1];
	}
	else if(x==1+len[n-1]+1){
		return P[n-1]+1;
	}else if(x<=2+len[n-1]*2){
		return 1+P[n-1]+f(n-1,x-(2+len[n-1]));
	}else{
		return 1+2*P[n-1];
	}
}


int main()
{
	P[0]=1;
	len[0]=1;
	for(int i=1;i<=50;i++){
		len[i]=len[i-1]*2+3;
		P[i]=P[i-1]*2+1;
	}
	LL n,x;
	cin>>n>>x;
	cout<<f(n,x)<<endl;

	return 0;
}

