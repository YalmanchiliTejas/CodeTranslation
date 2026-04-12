
#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;

int n;

int a[maxn];
int f[maxn];
int tot;

int main(){
	scanf("%d",&n);
	for(register int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	tot++;
	f[tot]=a[1];
	for(register int i=2;i<=n;i++){
		if(a[i]<=f[tot])
			f[++tot]=a[i];
		else{
			int l=1,r=tot,mid;
			while(l<r){
				int mid=(l+r)>>1;
				if(a[i]>f[mid])
					r=mid;
				else
					l=mid+1;
			}
			f[l]=a[i];
		}
	}
	printf("%d\n",tot);
	return 0;
}
