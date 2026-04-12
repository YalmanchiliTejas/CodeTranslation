#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define rep(i,a,b) for(int (i) = (a); (i) <= (b); i++)
#define repd(i,a,b) for(int (i) = (a); (i) >= (b); i--)
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define mp make_pair
#define pb push_back
using namespace std;
#define is_digit(c) ((c) >= '0' && (c) <= '9')
#define is_upper(c) ((c) >= 'A' && (c) <= 'Z')
#define is_lower(c) ((c) >= 'a' && (c) <= 'z')
#define readchar() ((char)fgetc(stdin))
#define printchar(c) fputc((c), stdout)
void readline(char *s) {int len=0;char c;for(c=readchar(); c!='\n'; s[len++]=c, c=readchar());s[len]=0;}
void readstr(char *s) {int len=0;char c;for(c=readchar(); c!=' '&&c!='\n'; s[len++]=c, c=readchar());s[len]=0;}
void printstr(const char *s) {int len=strlen(s);rep(i,0,len-1) printchar(s[i]);}
void to_lower(char *s, int L, int R) {rep(i,L,R) if (is_upper(s[i])) s[i]=s[i]-'A'+'a';}
void to_upper(char *s, int L, int R) {rep(i,L,R) if (is_lower(s[i])) s[i]=s[i]-'a'+'A';}
ll readll() {
	char c;ll ans=0, x=1;for (c=readchar(); !is_digit(c)&&c!='-'; c=readchar());
	if (c=='-') x=-1, c=readchar();for (; is_digit(c); ans=ans*10+c-'0', c=readchar());return ans*x;
}
void printll(ll x) {
	int a[25], cnt=0;if (x==0) { printchar('0'); return; }if (x<0) printchar('-'), x=-x;
	for (; x; a[cnt++]=x-x/10*10, x/=10);repd(i,cnt-1,0) printchar(a[i]+'0');
}
#define readint() ((int)readll())
#define printint(x) printll((ll)(x))
vector<pair<int,ll> > g[100005];
int n, x[100005], y[100005], ind[100005];
bool cmp(int i, int j) {
	return x[i]!=x[j]?x[i]<x[j]:y[i]<y[j];
}
ll calc(int i, int j) {
	if (i<1||j>n) return 0;
	return min(abs(x[ind[i]]-x[ind[j]]),abs(y[ind[i]]-y[ind[j]]));
}
vector<pair<ll,pii> > edge;
int par[100005];
int find(int x) {
	return (x==par[x]?x:par[x]=find(par[x]));
}
void merge(int x, int y) {
	x=find(x), y=find(y);
	par[y]=x;
}
ll mst() {
	rep(i,1,n) par[i]=i;
	ll ans=0;
	rep(i,1,n) rep(j,0,(int)g[i].size()-1) edge.pb(mp(g[i][j].second,mp(i,g[i][j].first)));
	sort(edge.begin(),edge.end());
	rep(i,0,(int)edge.size()-1) {
		int x=edge[i].second.first, y=edge[i].second.second;
		if (find(x)==find(y)) continue;
		merge(x,y);
		ans+=edge[i].first;
	}
	return ans;
}
int main() {
	n=readint();
	rep(i,1,n) x[i]=readint(),y[i]=readint(),ind[i]=i;
	sort(ind+1,ind+1+n,cmp);
	rep(i,1,n-1) {
		g[ind[i]].pb(mp(ind[i+1],calc(i,i+1)));
		g[ind[i+1]].pb(mp(ind[i],calc(i,i+1)));
	}
	rep(i,1,n) swap(x[ind[i]],y[ind[i]]);
	sort(ind+1,ind+1+n,cmp);
	rep(i,1,n-1) {
		g[ind[i]].pb(mp(ind[i+1],calc(i,i+1)));
		g[ind[i+1]].pb(mp(ind[i],calc(i,i+1)));
	}
	ll ans=mst();
	printll(ans);
	return 0;
}
