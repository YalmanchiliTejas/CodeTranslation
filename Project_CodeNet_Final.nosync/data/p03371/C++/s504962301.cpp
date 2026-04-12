#include<bits/stdc++.h>
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define re(i,a,n) for(int _tmp=n,i=a;i<_tmp;++i)
#define fec(i,a) for(__typeof a.begin() i=a.begin();i!=a.end();++i)
#define For(i,v,u) for(int i=H[u],v=to[i];i;i=nxt[i],v=to[i])
#define si(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inf 1e18
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
template<class T> inline void MAX(T&x,T y){if(x<y)x=y;}
template<class T> inline void MIN(T&x,T y){if(x>y)x=y;}
typedef long long ll;
typedef pair<int,int> pii;
const int N=111111;
//head
int a,b,c,x,y;
int ans;
int main() {
	read(a,b,c);
	c=c*2;
	read(x,y);
	if (a+b<=c){
		ans=a*x+b*y;
	}else{
		int xx=min(x,y);
		x-=xx;y-=xx;
		ans=c*xx;
		if(x){
			ans+=x*min(c,a);
		}else if(y){
			ans+=y*min(c,b);
		}
	}
	cout<<ans<<endl;
	return 0;
}