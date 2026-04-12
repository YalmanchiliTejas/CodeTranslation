#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#define oo 2000000000
#define M 500005
using namespace std;
int a[M];
int main(){
	int n;
	scanf("%d",&n);
	int l=250000;
	int r=250001;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(i%2){
			a[l--]=x;
		}
		else {
			a[r++]=x;
		}
	}
	if(n%2){
		for(int i=l+1;i<r;i++)printf("%d ",a[i]);
	}
	else for(int i=r-1;i>l;i--)printf("%d ",a[i]);
//	else cout<<a<<endl;
	return 0;
}