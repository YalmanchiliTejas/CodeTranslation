#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long 
#define ii pair<int,int>
#define iii pair<int,ii>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)/2)
#define all(x) x.begin(),x.end()
#define pw(x) (1<<(x))
#define inf 1000000005
#define MOD 1000000007 
#define N 105
#define M 1000003
#define LOG 20
#define KOK 250
#define EPS 0.0000001
using namespace std;

int n,cnt;
int tut[N],h[N],dp[N][N],vis[N][N];

int mul(int x,int y) {
	
	return (ll)x*y%MOD;

}

int add(int x,int y) {

	x+=y;

	if(x>=MOD) x-=MOD;
	if(x<0) x+=MOD;

	return x;

}

int fe(int x,int y) {

	if(y==0) return 1;
	if(y&1) return mul(x,fe(x,y-1));

	int res=fe(x,y>>1);

	return mul(res,res);

}

int f(int pos,int bef) {

	if(pos>n) return 1;

	if(vis[pos][bef]) return dp[pos][bef];

	vis[pos][bef]=1;

	int& r=dp[pos][bef];

	if(h[pos-1]>=h[pos]) {

		if(bef>h[pos]) {

			r=add(r,mul(2,f(pos+1,cnt+1)));

		}
		else {

			r=add(r,f(pos+1,bef));

		}

	}
	else {

		if(bef>h[pos]) {

			for(int i=h[pos-1]+1;i<=h[pos];i++) {

				r=add(r,mul(f(pos+1,i),mul(add(fe(2,tut[i]-tut[i-1]-(i-1==0)),MOD-1),fe(2,tut[h[pos]]-tut[i]))));

			}

			r=add(r,f(pos+1,cnt+1));

			r=mul(r,2);

		}
		else {

			r=add(r,mul(f(pos+1,bef),fe(2,tut[h[pos]]-tut[h[pos-1]])));

		}

	}

	return r;

}

void compress() {

	map<int,int> has;

	for(int i=1;i<=n;i++) has[h[i]]=1;

	for(auto& x:has) {

		++cnt;

		tut[cnt]=x.st;
		x.nd=cnt;

	}

	for(int i=1;i<=n;i++) h[i]=has[h[i]];

}

int main() {

	scanf("%d",&n);

	for(int i=1;i<=n;i++) {
	
		scanf("%d",h+i);
	
	}

	compress();

	printf("%d",f(1,cnt+1));

}