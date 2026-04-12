#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
int l=200000,r=200000,a[200010],b[400010];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	b[200000]=a[1];
	for(int i=2;i<=n;i++){
		if((n-i+1)&1){
			b[--l]=a[i];
		}else{
			b[++r]=a[i];
		}
	}
	for(int i=l;i<=r;++i){
		cout<<b[i]<<' ';
	}
	return 0;
}