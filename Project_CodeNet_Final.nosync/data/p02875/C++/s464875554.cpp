#include<bits/stdc++.h>
using namespace std;
const int Q=998244353;
inline int inv(int x){
	int r=1,y=Q-2;
	while(y){
		if(y&1) r=1LL*r*x%Q;
		x=1LL*x*x%Q;
		y>>=1;
	}
	return r;
}
int main(){
	int n,p3=1,cur=2;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		p3=p3*3LL%Q;
	}
	for(int i=0;i<n/2;i++){
		p3=(p3+Q-cur)%Q;
		cur=2LL*cur*(n-i)%Q*inv(i+1)%Q;
	}
	printf("%d\n",p3);
	return 0;
}