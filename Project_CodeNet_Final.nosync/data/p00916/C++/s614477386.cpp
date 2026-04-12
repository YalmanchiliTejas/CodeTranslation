#include <bits/stdc++.h>
using namespace std;
typedef vector <int> v;
v x[2],y[2];
int mp[1000][1000],w,h;

void saiki(int x,int y){
  int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
  mp[y][x]=1;
  for(int i=0;i<4;i++){
    int nx=x+dx[i],ny=y+dy[i];
    if(nx>=0&&ny>=0&&nx<=w&&ny<=h&&!mp[ny][nx])saiki(nx,ny); 
  }
}

int compress(v &x1,v &x2){
  vector <int> xs;

  for(int i=0;i<x1.size();i++)
    for(int j=-1;j<=1;j++){
      int tx1=x1[i]+j,tx2=x2[i]+j;
      xs.push_back(tx1);
      xs.push_back(tx2);
    }
  sort(xs.begin(),xs.end());
  xs.erase(unique(xs.begin(),xs.end()),xs.end());
  
  for(int i=0;i<x1.size();i++){
    x1[i]=find(xs.begin(),xs.end(),x1[i])-xs.begin();
    x2[i]=find(xs.begin(),xs.end(),x2[i])-xs.begin();
  }
  return xs.size()+1;
}

int main(){
  int n;
  while(cin>>n,n){;
    x[0].clear(),x[1].clear(),y[0].clear(),y[1].clear();
    for(int i=0,x1,x2,y1,y2;i<n;i++){
      cin>>x1>>y1>>x2>>y2;
      x1*=2,y1*=2,x2*=2,y2*=2;
      x[0].push_back(x1),x[1].push_back(x2);
      y[0].push_back(y1),y[1].push_back(y1);
      //
      x[0].push_back(x1),x[1].push_back(x2);
      y[0].push_back(y2),y[1].push_back(y2);
      //
      x[0].push_back(x1),x[1].push_back(x1);
      y[0].push_back(y2),y[1].push_back(y1);
      //
      x[0].push_back(x2),x[1].push_back(x2);
      y[0].push_back(y2),y[1].push_back(y1);
    }

    w=compress(x[0],x[1]),h=compress(y[0],y[1]);
    
    memset(mp,0,sizeof(mp));
    for(int i=0;i<x[0].size();i++)
      for(int j=y[0][i];j<y[1][i]+1;j++)
	for(int k=x[0][i];k<x[1][i]+1;k++)mp[j][k]=1;

    int ans=0;
    for(int i=0;i<=h;i++)
      for(int j=0;j<=w;j++)
	if(!mp[i][j]) ans++,saiki(j,i);

        cout <<ans<<endl; 
 }
  return 0;
}