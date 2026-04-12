#include<bits/stdc++.h>
using namespace std;

const int maxn = 200100;

int ord[maxn];
int a[maxn];
int ans[maxn];

bool cmp(int aa,int bb){
	return a[aa]<a[bb];
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		ord[i]=i;
	}
	sort(ord,ord+n,cmp);
	//for(int i=0;i<n;i++)printf("%d ",a[ord[i]]);puts("");
	for(int i=0;i<n;i++){
		if(i<n/2){
			ans[ord[i]]=a[ord[n/2]];
		}else{
			ans[ord[i]]=a[ord[n/2-1]];
		}
	}
	for(int i=0;i<n;i++)printf("%d\n",ans[i]);
	return 0;
}