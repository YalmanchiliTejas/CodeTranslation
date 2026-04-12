#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)

using ll = long long;

const ll MOD = 1000000007;

int n,m;
int dat[125252];

int root(int x){
	return dat[x]<0?x:dat[x]=root(dat[x]);
}
void unite(int a, int b){
	a=root(a); b=root(b);
	if(a==b)return;
	if(dat[a]>dat[b])swap(a,b);
	dat[a]+=dat[b];
	dat[b]=a;
}

int main(){
	while(true){
		scanf("%d%d",&n,&m);
		if(n==0 && m==0)break;
		fill(dat,dat+n,-1);
		REP(i,m){
			int a,b;
			scanf("%d%d",&a,&b);
			--a; --b;
			unite(a,b);
		}
		int c = 0;
		REP(i,n)if(root(i)==i)c++;
		ll ans = 1;
		REP(i,c)ans=ans*2%MOD;
		if(c != n){
			ans = (ans+1)%MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

