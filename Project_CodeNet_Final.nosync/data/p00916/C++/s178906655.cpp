#include<bits/stdc++.h>
#define M 300
#define N 50
using namespace std;
int n,ax[N],ay[N],bx[N],by[N],k,ans,minx,miny;
map<int,int> X,Y;
vector<int> x,y;
bool used[M][M];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

void init(int sx,int sy,int gx,int gy,int a){
  while(!(sx==gx&&sy==gy)){
    used[sy][sx]=true;
    sy+=dy[a],sx+=dx[a];
  }
  used[sy][sx]=true;
}

void dfs(int px,int py){
  used[py][px]=true;
  for(int i=0;i<4;i++){
    int nx=px+dx[i],ny=py+dy[i];
    if(nx<0||ny<0||M<=nx||M<=ny)continue;
    if(used[ny][nx])continue;
    dfs(nx,ny);
  }
}

int main(){
  while(1){
    cin>>n;
    if(!n)break;
    X.clear();
    Y.clear();
    x.clear();
    y.clear();
    minx=miny=(1e9);
    memset(used,0,sizeof(used));
    for(int i=0;i<n;i++){
      cin>>ax[i]>>ay[i]>>bx[i]>>by[i];
      minx=min(minx,min(ax[i],bx[i]));
      miny=min(miny,min(ay[i],by[i]));
    }
    for(int i=0;i<n;i++){
      ax[i]=ax[i]-minx+1;
      bx[i]=bx[i]-minx+1;
      ay[i]=ay[i]-miny+1;
      by[i]=by[i]-miny+1;
      x.push_back(ax[i]);
      x.push_back(bx[i]);
      y.push_back(ay[i]);
      y.push_back(by[i]);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    k=0;
    for(int i=1;i<(int)x.size();i++){
      if(x[i]-x[i-1]==1)X[x[i]]=x[i]+k+1,k++;
      else if(x[i]-x[i-1]>2)X[x[i]]=x[i-1]+k+2,k-=x[i]-(x[i-1]+2);
      else X[x[i]]=x[i]+k;
    }
    k=0;
    for(int i=1;i<(int)y.size();i++){
      if(y[i]-y[i-1]==1)Y[y[i]]=y[i]+k+1,k++;
      else if(y[i]-y[i-1]>2)Y[y[i]]=y[i-1]+k+2,k-=y[i]-(y[i-1]+2);
      else Y[y[i]]=y[i]+k;
    }
    for(int i=0;i<n;i++){
      if(X.find(ax[i])!=X.end())ax[i]=X[ax[i]];
      if(Y.find(ay[i])!=Y.end())ay[i]=Y[ay[i]];
      if(X.find(bx[i])!=X.end())bx[i]=X[bx[i]];
      if(Y.find(by[i])!=Y.end())by[i]=Y[by[i]];
      init(ax[i],ay[i],ax[i],by[i],0);
      init(ax[i],ay[i],bx[i],ay[i],1);
      init(bx[i],by[i],bx[i],ay[i],2);
      init(bx[i],by[i],ax[i],by[i],3);
    }
    ans=0;
    for(int i=0;i<M;i++)
      for(int j=0;j<M;j++)
	if(!used[i][j])ans++,dfs(j,i);
    cout<<ans<<endl;
  }
  return 0;
}