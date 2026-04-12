#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=105,P=1e9+7;
int n,h[N];
int fpow(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=1LL*k1*k1%P)if(k2&1)k3=1LL*k3*k1%P;
	return k3;
}
pair<int,int>sol(int l,int r,int bs){
	int mn=*min_element(h+l,h+r+1),coef=1,all=1,num=0;
	for(int i=l;i<=r;){
		if(h[i]!=mn){
			int j=i+1;
			while(j<=r&&h[j]!=mn)++j;
			pair<int,int>val(sol(i,j-1,mn));
			coef=1LL*coef*val.fi%P;
			all=1LL*all*(val.fi+val.se)%P;
			i=j;
		}else{
			++num,++i;
		}
	}
	return make_pair(1LL*coef*fpow(2,mn-bs)%P,(1LL*all*fpow(2,num)%P+1LL*coef*(fpow(2,mn-bs)+P-2)%P)%P);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",h+i);
	printf("%d\n",sol(1,n,0).se);
	return 0;
}