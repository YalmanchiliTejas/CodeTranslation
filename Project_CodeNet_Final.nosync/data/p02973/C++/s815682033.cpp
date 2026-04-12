#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn];
int d[maxn];
int main(){
	int i,j,k,m,n;
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int top=0;
	for(i=n;i>=1;i--){
		if(a[i]>=d[top])d[++top]=a[i];
		else {
			int x=upper_bound(d+1,d+top+1,a[i])-d;
			d[x]=a[i];
		}
	}
	printf("%d\n",top);
	return 0;
}