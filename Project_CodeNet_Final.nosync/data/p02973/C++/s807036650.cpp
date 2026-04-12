#include<bits/stdc++.h>
using namespace std;
#define reg register
#define M 200005
int fir,sec;
int A[M],n;
int B[M],m;
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d",A+i);
	for(int i=n; i>=1; --i) {
		int t=upper_bound(B+1,B+1+m,A[i])-B;
		if(t==m+1)B[++m]=A[i];
		else B[t]=A[i];
	}
	printf("%d",m);
}

