/*
向前走K步的时候，
跳A步的点：(n-1)-(k-1)*C (n-1)-(k-2)*c ... n-1;
跳B步的点：c 2*c 3*c ... (k-1)*c;
向前走K+1步的时候，
跳A步的点：(n-1)-k*c (n-1)-(k-1)*c ... n-1;
跳B步的点：c 2*c 3*c ... k*c;
而且会发现跳AB步的点的递增大小都是c.
所以可以发现多了一步其实就是多了 跳A步的 (n-1)-k*c 和 跳B步的 k*c.
而且把 跳B步的点反过来，可以发现是一一对应的。即
(n-1)-k*c (n-1)-(k-1)*c ... n-1
k*c        (k-1)*c      ....c
所以每次增加一步的时候，就只是多了当前点的边上这两个点。
所以枚举k的时候，从两边开始加，意思就是步数最小的，然后往里面收缩，步数增大。 
其实这里应该要反过来想，本来应该是从最里面开始往外面枚举，步数每增加一步，左右两边就加上
但是这里才用反着的思想，效果都是一样的。
*/
#include<bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORX(i,n) for(int i=1;i<=n;i++)
#define lscan(x) scanf("%lld",&x);
#define scan(x) scanf("%d",&x);
#define print(x) printf("%d",x);
#define lprint(x) printf("%lld",x);
typedef long long ll;
const int N=1e5+200;
ll s[N],x[N],n,temp,l,r,cnt=0; 
ll ans=0;
int main(){
	scanf("%d",&n);
	FOR(i,n) lscan(s[i]);
	for(int c=1;c<n-1;c++){//枚举每一个c，c的范围就是[1,n-2]. 不可能为n-1，A=N B=1是不成立 
		ll temp=0;
		l=0,r=n-1;
		cnt++;//cnt 的作用就是防止走到了空的地方 
		//对k进行枚举 
		while(l!=r&&r>c&&l<n-1&&x[l]!=cnt&&x[r]!=cnt){
			temp+=s[l];temp+=s[r];
			x[l]=x[r]=cnt;
			l+=c;r-=c;
			ans=max(ans,temp);
		} 
	}
	lprint(ans);
} 
 