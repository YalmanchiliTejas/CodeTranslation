#include<map>
#include<set>
#include<list>
#include<ctime>
#include<cmath>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define rep(i,s,t) for(register int i=s;i<=t;++i)
#define _rep(i,s,t) for(register int i=s;i>=t;--i)
#define Rep(i,s,t) for(register int i=s;i<t;++i)
#define go(x) for(register int e=las[x];e;e=nxt[e])
#define re register
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define is insert
#define es erase
#define pii pair<int,int>
#define ms(f,x) memset(f,x,sizeof f)
#define mc(f,x) memcpy(f,x,sizeof f)
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define gi(x) read(x)
#define gii(x,y) read(x),read(y)
#define giii(x,y,z) read(x),read(y),read(z)
namespace IO{
    #define gc getchar()
    #define pc(x) putchar(x)
    template<typename T>inline void read(T &x){
        x=0;int f=1;char ch=gc;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
        while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=gc;x*=f;return;
    }
    template<typename T>inline void write(T x=0){
        T wr[51];wr[0]=0;if(x<0)pc('-'),x=-x;if(!x)pc(48);
        while(x)wr[++wr[0]]=x%10,x/=10;while(wr[0])pc(48+wr[wr[0]--]);return;
    }
}
using IO::read;
using IO::write;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
int n;
int main(){
	gi(n);
	if(n>=30)puts("Yes");
	else puts("No");
	return 0;
}