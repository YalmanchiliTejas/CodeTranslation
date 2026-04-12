#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
int N,A[100005],l,r,B[100005],x;
long long Ans,Ret;
int main(){
	scanf("%d",&N);
	for (int i=1;i<=N;++i) scanf("%d",A+i);
	std::sort(A+1,A+1+N),l=1,r=N,x=A[(N+1)/2];
	for (int i=1;i<N;++i){
		if (i&1) Ans+=abs(A[l]-x),x=A[l++];
			else Ans+=abs(A[r]-x),x=A[r--];
	}
	l=1,r=N,x=A[(N+1)/2];
	for (int i=1;i<N;++i){
		if (i&1) Ret+=abs(A[r]-x),x=A[r--];
			else Ret+=abs(A[l]-x),x=A[l++];
	}
	return printf("%lld",max(Ans,Ret)),0;
}