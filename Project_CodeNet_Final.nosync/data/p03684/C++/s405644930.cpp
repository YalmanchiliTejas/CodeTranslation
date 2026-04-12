#include<ctime>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cassert>
#include<string>
#include<sstream>
#include<fstream>
#include<deque>
#include<queue>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<set>
#include<bitset>
#include<iomanip>
#include<utility>
#include<functional>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cwchar>
#include<cwctype>
#include<exception>
#include<locale>
#include<numeric>
#include<new>
#include<stdexcept>
#include<limits>
using namespace std;

#define ll long long
#define INF 1e9
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
#define pii pair<int,int>

int readint()
{
	char c;
	while(c=getchar(),(c<'0'||c>'9')&&c!='-');
	bool flag=(c=='-');
	if(flag)c=getchar();
	int x=0;
	while(c>='0'&&c<='9')
	{
		x=x*10+c-48;
		c=getchar();
	}
	return flag?-x:x;
}

const int maxn=100005;
int n;
class EDGE{
public:
	int from,to,m;
};
bool cmp(EDGE x,EDGE y){
	return x.m<y.m;
}
ll ans;
vector<EDGE>edge;
vector<pii>X,Y;
int f[maxn];

int Find(int x){
	return f[x]==x?x:f[x]=Find(f[x]);
}

void Union(int x,int y){
	x=Find(x);y=Find(y);
	if(x!=y)f[x]=y;
}

int main(){
	scanf("%d",&n);
	REP(i,n){
		int x,y;
		scanf("%d%d",&x,&y);
		X.push_back(mk(x,i));
		Y.push_back(mk(y,i));
		f[i]=i;
	}
	sort(X.begin(),X.end());
	rep(i,X.size()-1)
	edge.push_back((EDGE){X[i].se,X[i+1].se,X[i+1].fi-X[i].fi});
	sort(Y.begin(),Y.end());
	rep(i,Y.size()-1)
	edge.push_back((EDGE){Y[i].se,Y[i+1].se,Y[i+1].fi-Y[i].fi});
	sort(edge.begin(),edge.end(),cmp);
	rep(i,edge.size()){
		EDGE x=edge[i];
		if(Find(x.from)==Find(x.to))continue;
		Union(x.from,x.to);
		ans+=x.m;
	}
	printf("%lld",ans);
	return 0;
}