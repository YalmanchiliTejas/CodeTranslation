#include<bits/stdc++.h>
using namespace std;
int sum,h[100009];
int n,x,y,s[100009],f[100009];
struct tt{
    int to;
    int next;
    double w;
};
tt r[200009];
inline void add(int a,int b)
{
    r[++sum].to=b;
    r[sum].next=h[a];
    h[a]=sum;
    r[++sum].to=a;
    r[sum].next=h[b];
    h[b]=sum;
}
inline int boo(int x,int fa)
{
    s[x]=1;
    int ans=0;
    for(int i=h[x];i;i=r[i].next)
    {
        if(r[i].to==fa)
          continue;
        if(boo(r[i].to,x))
          return 1;
        if(s[r[i].to])
        {
            ans++;
            s[x]=0;
            if(ans==2)
              return 1;
        }
    }
    return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    if(boo(1,0)||s[1])
      printf("First");
    else 
      printf("Second");
      return 0;
}