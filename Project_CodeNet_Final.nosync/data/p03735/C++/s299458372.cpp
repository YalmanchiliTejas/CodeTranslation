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
const int MN=2e5+5;
int n,x[MN],y[MN],id[MN];
inline void swap(int& a,int& b){a^=b;b^=a;a^=b;}
inline bool cmp(int a,int b){return x[a]<x[b];}
inline ll min(ll a,ll b){return a<b?a:b;}
const int inf=0x7fffffff;
class Treap{
    private:
        int tot;
        struct node{int s[2],v,rnd,cnt,siz;}t[MN<<1];
        inline int rand(){
            static int seed=23333;
            return seed^=seed<<13,seed^=seed>>17,seed^=seed<<5;
        }
        inline void init(int x,int v){
            t[x].s[0]=t[x].s[1]=0;t[x].cnt=t[x].siz=1;t[x].v=v;t[x].rnd=rand();
        }
        inline void update(int x){t[x].siz=t[t[x].s[0]].siz+t[t[x].s[1]].siz+t[x].cnt;}
        inline void zig(int &x){
            reg int tmp=t[x].s[1];t[x].s[1]=t[tmp].s[0];t[tmp].s[0]=x;
            t[tmp].siz=t[x].siz;update(x);x=tmp;
        }
        inline void zag(int &x){
            reg int tmp=t[x].s[0];t[x].s[0]=t[tmp].s[1];t[tmp].s[1]=x;
            t[tmp].siz=t[x].siz;update(x);x=tmp;
        }
    public:
        int root;
        inline void ins(int &x,int v){
            if(!x){x=++tot;init(x,v);return;}
            t[x].siz++;
            if(t[x].v==v){t[x].cnt++;return;}
            if(t[x].v<v){
                ins(t[x].s[1],v);
                if(t[t[x].s[1]].rnd<t[x].rnd)zig(x);
            }
            else{
                ins(t[x].s[0],v);
                if(t[t[x].s[0]].rnd<t[x].rnd)zag(x);
            }
        }
        inline void del(int &x,int v){
            if(!x)return;
            if(t[x].v==v)
                if(t[x].cnt>1){t[x].cnt--,t[x].siz--;return;}
                else{
                    if(!(t[x].s[0]&&t[x].s[1])){x=t[x].s[0]+t[x].s[1];return;}
                    if(t[t[x].s[0]].rnd<t[t[x].s[1]].rnd)zig(x),del(x,v);
                    else zag(x),del(x,v);
                    return;
                }
            t[x].siz--;del(t[x].s[t[x].v<v],v);
        }
        inline int find(int x,int v){
            if(!x)return 0;
            if(t[x].v==v)return t[t[x].s[0]].siz+1;
            if(t[x].v<v)return t[t[x].s[0]].siz+t[x].cnt+find(t[x].s[1],v);
            return find(t[x].s[0],v);
        }
        inline int findx(int x,int k){
            if(!x)return 0;
            if(t[t[x].s[0]].siz>=k)return findx(t[x].s[0],k);
            k-=t[t[x].s[0]].siz;
            if(t[x].cnt>=k)return t[x].v;
            return findx(t[x].s[1],k-t[x].cnt);
        }
        inline int pre(int x,int v){
            if(!x)return -inf;
            if(t[x].v<v)return std::max(pre(t[x].s[1],v),t[x].v);
            return pre(t[x].s[0],v);
        }
        inline int suf(int x,int v){
            if(!x)return inf;
            if(t[x].v>v)return std::min(suf(t[x].s[0],v),t[x].v);
            return suf(t[x].s[1],v);
        }
        inline int begin(){
			reg int x=root;
			while(t[x].s[0])x=t[x].s[0];
			return t[x].v;
        }
        inline int end(){
			reg int x=root;
			while(t[x].s[1])x=t[x].s[1];
			return t[x].v;
        }
}s1,s2;
int main(){
	n=read<int>();reg int cnt,i;reg ll ans;
	for(i=1;i<=n;++i){
		x[i]=read<int>(),y[i]=read<int>();id[i]=i;
		if(x[i]>y[i])swap(x[i],y[i]);s1.ins(s1.root,x[i]);s2.ins(s2.root,y[i]);
	}
	std::sort(id+1,id+1+n,cmp);
	ans=1ll*(s1.end()-s1.begin())*(s2.end()-s2.begin());
	for(i=1;i<=n;++i){
		s1.del(s1.root,x[id[i]]);s2.ins(s2.root,x[id[i]]);s2.del(s2.root,y[id[i]]);s1.ins(s1.root,y[id[i]]);
		ans=min(ans,1ll*(s1.end()-s1.begin())*(s2.end()-s2.begin()));
	}
	printf("%lld\n",ans);
	return 0;
}