#include<bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<=n;i++)
#define rep2(i,k,n) for(int i=k;i>=n;i--)
using namespace std;
const int N=2e5+7;
int a[N],b[N],n;
int main(){
	scanf("%d",&n);rep(i,1,n)scanf("%d",&a[i]);
	int p=n;
	for(int i=1,j=n;i<=j;i++,j--){
		b[i]=a[p--];
		if(i<j)b[j]=a[p--];
	}
	rep(i,1,n)printf("%d ",b[i]);
}