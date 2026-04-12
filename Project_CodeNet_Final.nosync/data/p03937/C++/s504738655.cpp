#include<iostream>
using namespace std;
int n,m,dx[2]={0,1},dy[2]={1,0};char a[9][9];
struct data{int x,y;}que[1000];
void bfs()
{
  int h=0,t=1,xx,yy;
  que[0].x=que[0].y=1,a[1][1]='.';
  while(h!=t)
  {
    for(int i=0;i<2;i++)
    {
      xx=que[h].x+dx[i];
      yy=que[h].y+dy[i];
      if(xx<1||yy<1||xx>n||yy>m||a[xx][yy]=='.')continue;
      que[t].x=xx,que[t].y=yy,t++,a[xx][yy]='.';
      break;
    }
    h++;
  }
}
int main()
{
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin>>a[i][j];
  bfs();
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(a[i][j]=='#'){cout<<"Impossible"<<endl;return 0;}
  cout<<"Possible"<<endl;
  return 0;
}
