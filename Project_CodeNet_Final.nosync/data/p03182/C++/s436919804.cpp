#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
void read(int &x){
	int res=1;
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	if (ch=='-') res=-1,ch=getchar();
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
	x*=res;
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,m,n_=1;
ll ans,dp[200004],dat[524300],cnt[524300];
vector<pii>der[200004];
vector<int>inc[200004];
void upd(int l,int r,int id,int a,int b,ll add){
	if (r<a || b<l) return;
	if (a<=l && r<=b){
		dat[id]+=add;
		cnt[id]+=add;
		return;
	}
	upd(l,(l+r)/2,id*2+1,a,b,add);
	upd((l+r)/2+1,r,id*2+2,a,b,add);
	dat[id]=max(dat[id*2+1],dat[id*2+2])+cnt[id];
}
int main(){
	read(n),read(m);
	while (n_<=n) n_<<=1;
	for (int i=0;i<m;i++){
		int l,r,x;read(l),read(r),read(x),inc[l].push_back(x),der[r].push_back(mkp(l,x));
	}
	for (int i=0;i<524300;i++) dat[i]=-1e17;
	upd(0,n_-1,0,0,0,1e17);
	for (int i=1;i<=n;i++){
		for (int j=0;j<inc[i].size();j++)
			upd(0,n_-1,0,0,i-1,inc[i][j]);
		dp[i]=dat[0];
		upd(0,n_-1,0,i,i,dp[i]+100000000000000000);
		for (int j=0;j<der[i].size();j++)
			upd(0,n_-1,0,0,der[i][j].fi-1,-der[i][j].se);
	}
	for (int i=1;i<=n;i++)ans=max(ans,dp[i]);
	write(ans);
}