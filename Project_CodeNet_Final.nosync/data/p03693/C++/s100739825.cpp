#include<bits/stdc++.h>
using namespace std;
inline long long getnum()
{
    long long now=0;long long fh=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')fh=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){now=(now<<3)+(now<<1)+ch-'0';ch=getchar();}
    return now*fh;
}
int main()
{
  int x=getnum()*100;
  x+=getnum()*10;
  x+=getnum();
  if (x%4==0) printf("YES\n");else printf("NO\n");
    return 0;
}