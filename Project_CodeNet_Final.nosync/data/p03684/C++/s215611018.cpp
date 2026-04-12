#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;
#define inf 1<<29
#define nu 1000005
#define maxnum 100005
#define num 30
int n;
struct Md
{
    int v,u,flag;

}M[maxnum],C[maxnum];
struct Node
{
    int x,y,z;

}dis[nu];
bool cmp(Md a,Md b){
   return a.v<b.v;
}
bool cmp0(Md a,Md b){
   return a.u<b.u;
}
bool cmp1(Node a,Node b){
   return a.z<b.z;
}
int book[maxnum];
void init()
{
    for(int i=1;i<=n;i++)
        book[i]=i;

}
int getx(int x)
{
    if(book[x]!=x)
        book[x]=getx(book[x]);
    return book[x];
}
void mergexy(int x,int y)
{
     book[y]=x;
}
void change(){
    for(int i=1;i<=n;i++)
        {
            C[i].v=M[i].v;
            C[i].u=M[i].u;
            C[i].flag=M[i].flag;
        }
}
int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
         scanf("%d%d",&M[i].v,&M[i].u);
         M[i].flag=i;
    }
  /*  int t=unique(M+1,M+n)-M;

      n=t;*/
      change();
      int fl=0;
      sort(C+1,C+n+1,cmp);
      for(int i=1;i<n;i++)
      {
          dis[++fl].x=C[i].flag,dis[fl].y=C[i+1].flag,dis[fl].z=(min(fabs(C[i].v-C[i+1].v),fabs(C[i].u-C[i+1].u)));
      }
      change();
      sort(C+1,C+n+1,cmp0);
      for(int i=1;i<n;i++)
      {
          dis[++fl].x=C[i].flag,dis[fl].y=C[i+1].flag,dis[fl].z=(min(fabs(C[i].v-C[i+1].v),fabs(C[i].u-C[i+1].u)));
      }
    sort(dis+1,dis+fl+1,cmp1);
   /*  cout<<flag<<endl;
    for(int i=1;i<=flag;i++)
        cout<<dis[i].z<<endl;*/
        init();
         int number=0;
        int sum=0;
       for(int i=1;i<=fl;i++)
        {
            int p=getx(dis[i].x),q=getx(dis[i].y);
            if(p!=q){
                mergexy(p,q);
                number++;
                sum+=dis[i].z;
        }
        if(number==n)  break;
    }
   cout<<sum<<endl;
    return 0;
}
