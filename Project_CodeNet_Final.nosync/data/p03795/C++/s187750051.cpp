#include <stdio.h>
#include <bits/stdc++.h>

#define endl "\n"
#define si(a) scanf("%d ",&a);
#define si2(a,b) scanf("%d %d ",&a,&b);
#define si3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sll(a) scanf("%lld ",&a);
#define sll2(a,b) scanf("%lld%lld",&a,&b)
#define sll3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define sf(a) scanf("%f ",&a);
#define sd(a) scanf("%lf ",&a);
#define sc(a) scanf("%c ",&a);
#define ss(a) scanf("%s ",a);
#define sf2(a,b) scanf("%f %f ",&a,&b);
#define sd2(a,b) scanf("%lf %lf ",&a,&b);
#define sz s.size();
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define forq(i,q,n) for(int i=q;i<n;i++)
#define form(i,n) for(int i=n;i>=0;i--)
#define forp(i,q,n) for(int i=q;i>=n;i--)
#define fi first
#define se second
#define INF 1000000010
#define MOD 1000000007
#define MAXN
#define LL long long int


using namespace std;

int n;

void init(){
	si(n);
	LL m = n * 800;
	int div = n / 15;
	LL sub = m - (div * 200);
	printf("%lld\n", sub);
}

int main(){
	
	init();
	return 0;
}