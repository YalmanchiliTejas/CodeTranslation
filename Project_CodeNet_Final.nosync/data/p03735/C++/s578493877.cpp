#include <bits/stdc++.h>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
const int N = 500050;
using namespace std;
int gi(){
  char ch=getchar(); int x=0,q=0;
  while(ch<'0' || ch>'9') (ch=='-'?q=1:0),ch=getchar();
  while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
  return q?(-x):x;
}
int x[N],t[N],y[N],o[N],tot,top;
long long ans=1e18;
struct d{
  int x,s;
  bool operator < (const d &c) const {
    return s<c.s;
  }
}p[N];
int main(){
  int n=gi(),m=0,g=0;
  for (int i=1; i<=n; ++i){
    x[i]=gi(),y[i]=gi();
    p[++tot]=(d){i,o[++top]=x[i]};
    p[++tot]=(d){i,o[++top]=y[i]};
  }
  sort(p+1,p+tot+1);
  sort(o+1,o+top+1);
  top=unique(o+1,o+top+1)-o-1;
  for (int i=1; i<=tot; ++i)
    p[i].s=lower_bound(o+1,o+top+1,p[i].s)-o;
  int a=1e9,b=-1e9,c=1e9,d=-1e9;
  for (int i=1; i<=n; ++i){
    if (x[i]<y[i]) swap(x[i],y[i]);
    a=Min(a,x[i]),b=Max(b,x[i]);
    c=Min(c,y[i]),d=Max(d,y[i]);
  }
  ans=Min(ans,1ll*(b-a)*(d-c));
  for (int i=1; i<=tot; ++i){
    while(m!=n&&g<tot){
      ++t[p[++g].x];
      if (t[p[g].x]==1)
	++m;
    }
    if (m==n)
      ans=Min(ans,1ll*(b-c)*(o[p[g].s]-o[p[i].s]));
    --t[p[i].x];
    if (!t[p[i].x]) --m;
  }
  cout<<ans;
  return 0;
}
