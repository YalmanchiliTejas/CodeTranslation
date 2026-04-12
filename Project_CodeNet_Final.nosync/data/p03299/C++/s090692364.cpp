#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;
const int mod = 1e9+7;
int ad(int x,int y) { x+=y; return x>=mod?x-mod:x; }
int mu(int x,int y) { return 1ll*x*y%mod; }
int sb(int x,int y) { x-=y; return x<0?x+mod:x; }
int ksm(int a,int b) {
	int ans = 1;
	for(;b;b>>=1,a=mu(a,a))
		if(b&1) ans = mu(ans,a);
	return ans;
}
int n,h[1005];

struct node{
	int s0,s1;
}; //s0 no xiangling s1 suiyi

node DC(int l,int r,int lm) {
	int x0 = 1 , x1 = 1 , cc = 0;
	int mimi = 0x3f3f3f3f;
	for(int i=l;i<=r;i++) {
		mimi = min(mimi,h[i]);
	}
	for(int i=l;i<=r;i++) cc += (h[i]==mimi);
	for(int i=l,j;i<=r;i=j+1) {
		j = i;
		if(h[i]>mimi) {
			while(j+1<=r&&h[j+1]!=mimi) j++;
			node yoo = DC(i,j,mimi);
			x0 = mu(x0,yoo.s0); x1 = mu(x1,ad(yoo.s0,yoo.s1));
		}
	}
	return (node){mu(x0,ksm(2,mimi-lm)),ad(mu(x0,sb(ksm(2,mimi-lm),2) ),mu(x1,ksm(2,cc))) };
}

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&h[i]);
	}
	node ans = DC(1,n,0);
	printf("%d",ans.s1);
}
//