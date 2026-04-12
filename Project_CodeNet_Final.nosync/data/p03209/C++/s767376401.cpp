#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i <= k;++i)
#define repp(i,j,k) for(int i = j;i >= k;--i)
#define rept(i,x) for(int i = linkk[x];i;i = e[i].n)
#define P pair<int,int>
#define Pil pair<int,ll>
#define Pli pair<ll,int>
#define Pll pair<ll,ll>
#define pb push_back 
#define pc putchar
#define mp make_pair
#define file(k) memset(k,0,sizeof(k))
#define ll long long
ll rd()
{
	ll num = 0;char c = getchar();bool flag = true;
	while(c < '0'||c > '9') {if(c == '-') flag = false;c = getchar();}
	while(c >= '0' && c <= '9') num = num*10+c-48,c = getchar();
	if(flag) return num;else return -num;
}
ll n,x;
ll num;
ll v[55],ans;
void solve(ll l,ll r,int level)
{
	if(l>r) return;
	if(l == r) {ans += l <= x;return;}
	ll mid = l+r>>1;
	if(x>mid) ans += v[level-1]+1,solve(mid+1,r-1,level-1);
	else if(x == mid) ans += v[level-1]+1;
	else solve(l+1,mid-1,level-1);
}
int main()
{
	n = rd();x = rd();
	num = 1;v[0] = 1;
	rep(i,1,n) num = num*2+3;
	rep(i,1,n) v[i] = v[i-1]*2+1;
	solve(1,num,n);
	printf("%lld\n",ans);
	return 0;
}