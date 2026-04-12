#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const long long p=1e9+7;
int main()
{
    int n=read(),tmp;
    long long x=0,y=0;
    for(int i=1; i<=n; i++) tmp=read(),x+=1LL*tmp*tmp,x%=p,y+=tmp,y%=p;
    y*=y,y%=p,y+=p,y-=x,y%=p,y*=(p+1)/2,y%=p;
    cout<<y<<endl;
    return 0;
}