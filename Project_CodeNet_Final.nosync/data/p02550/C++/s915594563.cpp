#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t,class ...A> inline void read(t &x,A &...a){
	read(x);read(a...);
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

#define int long long

int n,s,m,ans,cnt,tot,nxt[1000000],pos;
bool v[1000000];
vector<int> sum;

signed main(){
	read(n,s,m);
	sum.push_back(0);
	for(int i=s;!v[i];i=i*i%m) nxt[i]=i*i%m,v[i]=1,cnt++,sum.push_back(sum.back()+i),pos=i*i%m;
	tot=cnt;
	for(int i=s;i!=pos;i=nxt[i]) cnt--;
	ans=sum[min(tot-cnt,n)];
	if(n>tot-cnt){
		n-=tot-cnt;
		ans+=(sum[tot]-sum[tot-cnt])*(n/cnt)+sum[n%cnt+tot-cnt]-sum[tot-cnt];
	}
	write(ans);
}