#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
inline void Rd(int &res){
	char c;res=0;
	while(c=getchar(),c<'0');
	do{
		res=(res<<1)+(res<<3)+(c^48);
	}while(c=getchar(),c>='0');
}
const int M=(int)2e5+5;
int n,A[M],B[M];
int main(){
	Rd(n);
	for(int i=1;i<=n;i++)Rd(A[i]);
	if(n&1){
		int L=n/2+1,R=n/2+1;
		B[L]=A[1];
		for(int i=2;i<=n;i++){
			if(i&1)B[--L]=A[i];
			else B[++R]=A[i];
		}
	}else{
		int L=n/2+1,R=n/2+1;
		B[L]=A[1];
		for(int i=2;i<=n;i++){
			if(i&1)B[++R]=A[i];
			else B[--L]=A[i];
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d%c",B[i]," \n"[i==n]);
	return 0;
}