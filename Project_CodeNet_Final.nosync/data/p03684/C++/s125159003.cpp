#include<bits/stdc++.h> //Ithea Myse Valgulious
namespace chtholly{
typedef long long ll;
#define re0 register int
#define rec register char
#define rel register ll
#define gc getchar
#define pc putchar
#define p32 pc(' ')
#define pl puts("")
/*By Citrus*/
inline int read(){
  int x=0,f=1;char c=gc();
  for (;!isdigit(c);c=gc()) f^=c=='-';
  for (;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^'0');
  return f?x:-x;
  }
template <typename mitsuha>
inline bool read(mitsuha &x){
  x=0;int f=1;char c=gc();
  for (;!isdigit(c)&&~c;c=gc()) f^=c=='-';
  if (!~c) return 0;
  for (;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^'0');
  return x=f?x:-x,1;
  }
template <typename mitsuha>
inline int write(mitsuha x){
  if (!x) return pc(48);
  if (x<0) x=-x,pc('-');
  int bit[20],i,p=0;
  for (;x;x/=10) bit[++p]=x%10;
  for (i=p;i;--i) pc(bit[i]+48);
  return 0;
  }
inline char fuhao(){
  char c=gc();
  for (;isspace(c);c=gc());
  return c;
  }
}using namespace chtholly;
using namespace std;
const int yuzu=1e5;
int n=read();
struct node{
int x,y,id;
bool operator <(const node &b) const{
  return x<b.x;
  }
}a[yuzu|10];

bool cmp(node a,node b){return a.y<b.y;}

struct edge{
int u,v;ll cost;
bool operator <(const edge &b) const{
  return cost<b.cost;
  }
}bian[yuzu<<1|10];

struct dsu{
int fa[yuzu|10];
void init(int n){for (int i=1;i<=n;++i) fa[i]=i;}
int find(int x){return fa[x]^x?fa[x]=find(fa[x]):x;}
void mg(int u,int v){fa[find(u)]=find(v);}
}my_;

bool same(int u,int v){
return my_.find(u)==my_.find(v);
}
ll ans;

int main(){
int i,cnt=0;
for (i=1;i<=n;++i) a[i].x=read(),a[i].y=read(),a[i].id=i;
sort(a+1,a+n+1);
for (i=1;i<n;++i) bian[++cnt]={a[i].id,a[i+1].id,a[i+1].x-a[i].x};
sort(a+1,a+n+1,cmp);
for (i=1;i<n;++i) bian[++cnt]={a[i].id,a[i+1].id,a[i+1].y-a[i].y};
sort(bian+1,bian+cnt+1);
my_.init(n);
for (i=1;i<=cnt;++i){
  if (same(bian[i].u,bian[i].v)) continue;
  my_.mg(bian[i].u,bian[i].v);
  ans+=bian[i].cost; 
  }
write(ans);
}