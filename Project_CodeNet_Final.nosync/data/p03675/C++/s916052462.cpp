#include<bits/stdc++.h>
using namespace std;
#define M 200005

int n,A[M<<1];
int main(){
	scanf("%d",&n);
	int l=M,r=M-1,t=0;
	while(n--){
		int x;
		scanf("%d",&x);
		if(t==0)A[--l]=x;
		else A[++r]=x;
		t=!t;
	}
	if(t==1)for(int i=l;i<=r;i++)printf("%d ",A[i]);
	if(t==0)for(int i=r;i>=l;i--)printf("%d ",A[i]);
	puts("");
    return 0;
}