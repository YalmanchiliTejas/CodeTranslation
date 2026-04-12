#include<bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<=n;i++)
#define rep2(i,k,n) for(int i=k;i>=n;i--)
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int N=2e5+7;
ll ans=0x3f3f3f3f3f3f3f3full;
int n,Rmx,Rmi,Bmx,Bmi,tot;
struct data{
	int v,c;data(int v=0,int c=0):v(v),c(c){}
}a[N<<1];
bool operator < (const data& a,const data& b){
	return a.v < b.v;
}
void to_R(int x){
	Rmx=max(Rmx,x);
	Rmi=min(Rmi,x);
}
void to_B(int x){
	Bmx=max(Bmx,x);
	Bmi=min(Bmi,x);
}
int vis[N];
void solve1(){
	memset(vis,0,sizeof(vis));
	Rmx=0,Rmi=inf,Bmx=0,Bmi=inf;
	rep(i,1,tot){
		if(!vis[a[i].c])vis[a[i].c]=1,to_R(a[i].v);
		else to_B(a[i].v);
	}
	ans=min(ans,1ll*(Rmx - Rmi)*(Bmx - Bmi));
}
int cnt=0;
bool pan(int l,int r){
	memset(vis,0,sizeof(vis));
	cnt=0;
	rep(i,l,r){
		if(!vis[a[i].c])vis[a[i].c]=1,cnt++;
	}
	return cnt>=n;
}
bool ins(int x){
	if(cnt==n)return false;
	vis[a[x].c]++;
	if(vis[a[x].c]==1)cnt++;
	if(cnt==n)return false;
	return true;
}
void del(int x){
	vis[a[x].c]--;
	if(!vis[a[x].c])cnt--; 
}
void solve2(){
	Rmx=0,Rmi=inf,Bmx=0,Bmi=inf;
	to_R(a[1].v);
	to_R(a[tot].v);
	int L,R;
	rep(i,2,tot)if(a[i].c == a[1].c)L=i;
	rep(i,1,tot-1)if(a[i].c == a[tot].c)R=i;
	if(L>R)swap(L,R);
	if(pan(L,R)){
		ans=min(ans,1ll*(Rmx - Rmi)*(a[R].v - a[L].v));
	}else{
		memset(vis,0,sizeof(vis));
		int r=2;
		cnt=0;
		rep(l,2,tot-1){
			for(;r<=tot-1 && ins(r);)r++;
			if(cnt==n){
				if(l<=L && r>=R){
					ans=min(ans,1ll*(Rmx - Rmi)*(a[r].v - a[l].v));
				}
			}
			del(l);
		}
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int x;
		rep(k,0,1){
			scanf("%d",&x);
			a[++tot]=data(x,i);
		}
	}sort(a+1,a+tot+1);
	solve1();
	if(a[1].c != a[tot].c)
		solve2();
	printf("%lld\n",ans);
} 