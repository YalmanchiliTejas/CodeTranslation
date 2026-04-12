#include<bits/stdc++.h>
using namespace std;

int main()
{
  int H,W;cin>>H>>W;
  char a[H][W];set<int> sh,sw;
  for(int i=0;i<H;i++)sh.insert(i);
  for(int i=0;i<W;i++)sw.insert(i);
  for(int i=0;i<H;i++)for(int j=0;j<W;j++)cin>>a[i][j];
  for(int i=0;i<H;i++)for(int j=0;j<W;j++)if(a[i][j]=='#')sh.erase(i);
  for(int i=0;i<W;i++)for(int j=0;j<H;j++)if(a[j][i]=='#')sw.erase(i);
  for(int i=0;i<H;i++){if(sh.count(i))continue;for(int j=0;j<W;j++)if(!sw.count(j))cout<<a[i][j];cout<<endl;}
}