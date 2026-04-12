#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 200005
int a[M],id[M];
int main(){
	int n;
	scanf("%d",&n);
	int l=1,r=n,res=n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(i&1)id[l++]=res--;
		else id[r--]=res--;
	}
	for(int i=1;i<=n;i++)printf("%d ",a[id[i]]);
	puts("");
	return 0;
}