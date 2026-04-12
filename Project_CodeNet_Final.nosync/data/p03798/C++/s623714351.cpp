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
inline void read(rel &x){
  x=0;int f=1;char c=gc();
  for (;!isdigit(c);c=gc()) f^=c=='-';
  for (;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^'0');
  x=f?x:-x;
  }
template <typename mitsuha>
inline int write(mitsuha x){
  if (!x) return pc(48);
  if (x<0) x=-x,pc('-');
  re0 bit[20],i,p=0;
  for (;x;x/=10) bit[++p]=x%10;
  for (i=p;i;--i) pc(bit[i]+48);
  }
inline char fuhao(){
  rec c=gc();
  for (;isspace(c);c=gc());
  return c;
  }
}using namespace chtholly;
using namespace std;
const int yuzu=1e5;
/*
Ä³¸ö¶¯ÎïxµÄÖÖÀàÎªËüÇ°Á½¸ö¶¯ÎïµÄÖÖÀàºÍËüÇ°Ò»¸ö¶¯ÎïµÄÖÖÀàºÍ»Ø´ðµÄÒì»ò.
ÁîÑòÎª1,ÀÇÎª0,»Ø´ðoÎª1,xÎª0.
Ôòans[x]=ans[x-2]=='S'^ans[x-1]=='S'^c[x-1]=='o'; 
*/
char c[yuzu|10],ans[yuzu|10];
int n=read();

int judge(int x){
ans[x]=(ans[x-2]=='S')^(ans[x-1]=='S')^(c[x-1]=='o')?'S':'W';
if (x==n){
  return ((ans[x-1]=='S')^(ans[x]=='S')^(c[x]=='o')^(ans[1]=='W')) 
         &&((ans[x]=='S')^(ans[1]=='S')^(c[1]=='o')^(ans[2]=='W'));
  }
return judge(x+1); 
}

int main(){
scanf("%s",c+1);
ans[1]=ans[2]='S';
if (judge(3)) return puts(ans+1),0;
ans[2]='W';
if (judge(3)) return puts(ans+1),0;
ans[1]='W',ans[2]='S';
if (judge(3)) return puts(ans+1),0;
ans[2]='W';
if (judge(3)) return puts(ans+1),0;
puts("-1");
}