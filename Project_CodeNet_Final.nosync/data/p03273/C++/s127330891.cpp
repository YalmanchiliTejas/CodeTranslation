#include<bits/stdc++.h> //Ithea Myse Valgulious
namespace chtholly{
typedef long long ll;
#define re0 register int
#define rel register ll
#define rec register char
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
  if (!x) return 0&pc(48);
  if (x<0) pc('-'),x=-x;
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
const int z=105;
char c[z][z];int vish[z],visl[z];
int main(){
int i,j,n=read(),m=read();
for (i=1;i<=n;++i) scanf("%s",c[i]+1);
for (i=1;i<=n;++i){
  int bo=0;
  for (j=1;j<=m;++j) if (c[i][j]=='#') bo=1;
  if (!bo) vish[i]=1; 
  }  
for (i=1;i<=m;++i){
  int bo=0;
  for (j=1;j<=n;++j) if (c[j][i]=='#') bo=1;
  if (!bo) visl[i]=1;
  }
int bo;
for (i=1;i<=n;++i,bo?pl:0)
  for (bo=0,j=1;j<=m;++j) if (!vish[i]&&!visl[j]) pc(c[i][j]),bo=1;
}