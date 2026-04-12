#include<bits/stdc++.h>
using namespace std;
#define N (100010)
#define ll long long
int n,a[N],t[N];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		bool f=0;
		int l=1,r=t[0],ans=0;
		while (l<=r){
			int mid=(l+r)>>1;
			if (t[mid]<a[i]) ans=mid,r=mid-1;
			else l=mid+1;
		}
		if (ans) t[ans]=a[i];
		else t[++t[0]]=a[i];
	}
	printf("%d",t[0]);
}
