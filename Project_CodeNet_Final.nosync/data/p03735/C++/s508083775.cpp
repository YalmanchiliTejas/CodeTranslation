#include<cstdio>
#include<cctype>
#include<cstring>
#include<set>
#include<algorithm>
#define reg register
typedef long long ll;
template<typename T>inline T read(){
    reg T x=0;reg short f=1;reg char c=getchar();
    for(;!isdigit(c);f=c=='-'?-1:1,c=getchar());
    for(;isdigit(c);x=x*10+(c^48),c=getchar());
    return x*f;
}
using std::multiset;
const int MN=2e5+5;
int n,x[MN],y[MN],id[MN];
inline void swap(int& a,int& b){a^=b;b^=a;a^=b;}
inline bool cmp(int a,int b){return x[a]<x[b];}
inline ll min(ll a,ll b){return a<b?a:b;}
multiset<int>s1,s2;
int main(){
	n=read<int>();reg int cnt,i;reg ll ans;
	for(i=1;i<=n;++i){
		x[i]=read<int>(),y[i]=read<int>();id[i]=i;
		if(x[i]>y[i])swap(x[i],y[i]);s1.insert(x[i]);s2.insert(y[i]);
	}
	std::sort(id+1,id+1+n,cmp);
	ans=1ll*(*s1.rbegin()-*s1.begin())*(*s2.rbegin()-*s2.begin());
	for(i=1;i<=n;++i){
		s1.erase(s1.find(x[id[i]]));s2.insert(x[id[i]]);
		s2.erase(s2.find(y[id[i]]));s1.insert(y[id[i]]);
		ans=min(ans,1ll*(*s1.rbegin()-*s1.begin())*(*s2.rbegin()-*s2.begin()));
	}
	printf("%lld\n",ans);
	return 0;
}