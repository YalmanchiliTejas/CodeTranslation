#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define _rep(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define N 200005
int a[N],b[N],n;
int x,y;
std::vector<int> p,q;
int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0),std::cout.tie(0);
	std::cin>>n;
	rep(i,1,n) std::cin>>a[i],b[i]=a[i];
	std::sort(b+1,b+n+1);
	x=b[n>>1],y=b[(n>>1)+1];
	/*rep(i,1,n){
		if(x==a[i]) p.push_back(i);
		if(y==a[i]) q.push_back(i);
	}*/
	rep(i,1,n){
		if(a[i]>=y) std::cout<<x<<'\n';
		else std::cout<<y<<'\n';
	}
	return 0;
}