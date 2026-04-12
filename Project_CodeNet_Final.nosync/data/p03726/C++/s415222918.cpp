#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const double PI=acos(-1);
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define Rep(i,a,b) for (int i=(a);i<(b);i++)
#define Per(i,a,b) for (int i=(a);i>(b);i--)
#define travel_set(it,a) for (set<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define travel_map(it,a) for (map<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define travel_vec(it,a) for (vector<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define p(x) cout << x << endl;
#define def cout << "find" << endl;
#define what_is(x) cout << #x << " is " << x << endl;
template <class T>T sqr(T x){return x*x;}
template <class T>T alex(T x){return (x>0)?x:-x;}
template <class T>void read(T&x){
	x=0;T f=1;char ch=getchar();
	while ((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if (ch=='-')f=-1,ch=getchar();
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=f;
}

//---------------------------------------------------head---------------------------------------------------

#define maxn 100005
struct Ed{
	int sn[maxn<<1],nx[maxn<<1],ln[maxn],tt;
	void add(int x,int y){
		tt++;sn[tt]=y;nx[tt]=ln[x];ln[x]=tt;
		tt++;sn[tt]=x;nx[tt]=ln[y];ln[y]=tt;
	}
}ed;
int n;
bool vis[maxn],used[maxn];
void dfs(int x){
	vis[x]=true;int cn=0;
	for (int j=ed.ln[x];j;j=ed.nx[j])if (!vis[ed.sn[j]]){
		dfs(ed.sn[j]);if (!used[ed.sn[j]])cn++;
	}
	if (cn>1){printf("First\n");exit(0);}
	if (cn==1)used[x]=true;
}
int main(){
	read(n);if (n&1){printf("First\n");return 0;}
	Rep(i,1,n){
		int x,y;read(x);read(y);
		ed.add(x,y);
	}
	dfs(1);printf("Second\n");return 0;
}