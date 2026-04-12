#include<bits/stdc++.h>
using namespace std;
#define MAX 50
#define MAX2 105

int n;
int ay[MAX],ax[MAX],by[MAX],bx[MAX];
vector<int> Y,X;
map<int,int> my,mx;

void func(vector<int> &Y,map<int,int> &my,int ay[MAX],int by[MAX]){
  sort(Y.begin(),Y.end());
  int cnt=1;
  for(int i=0;i<n*2;i++){
    if(i&&Y[i]==Y[i-1])continue;
    my[Y[i]]=cnt++;
  }
  for(int i=0;i<n;i++){
    ay[i]=my[ay[i]];
    by[i]=my[by[i]];
  }
}

bool visited[MAX2][MAX2];
bool t[MAX2][MAX2][2];

void rec(int y,int x){
  if(y<0||x<0)return;
  if(y>=MAX2||x>=MAX2)return;
  if(visited[y][x])return;
  visited[y][x]=true;
  
  if(t[y][x+1][0]){
    rec(y,x+1);
  }
  if(t[y+1][x][1]){
    rec(y+1,x);
  }
  if(t[y][x][0]){
    rec(y,x-1);
  }
  if(t[y][x][1]){
    rec(y-1,x);
  }
}

int solve(){
  for(int i=0;i<MAX2;i++){
    for(int j=0;j<MAX2;j++){
      visited[i][j]=false;
      t[i][j][0]=t[i][j][1]=true;
    }
  }
  for(int i=0;i<n;i++){
    for(int y=ay[i];y<by[i];y++)
      t[y][ax[i]][0]=t[y][bx[i]][0]=false;
    for(int x=ax[i];x<bx[i];x++)
      t[ay[i]][x][1]=t[by[i]][x][1]=false;
  }
  
  int res=0;
  for(int i=0;i<MAX2;i++){
    for(int j=0;j<MAX2;j++){
      if(visited[i][j])continue;
      rec(i,j);
      res++;
    }
  }
  return res;
}

void init(){
  Y.clear();
  X.clear();
  my.clear();
  mx.clear();
}

int main(){
  while(1){
    cin>>n;
    if(n==0)break;
    init();
    for(int i=0;i<n;i++){
      cin>>ay[i]>>ax[i]>>by[i]>>bx[i];
      if(ay[i]>by[i])swap(ay[i],by[i]);
      if(ax[i]>bx[i])swap(ax[i],bx[i]);
      Y.push_back(ay[i]);
      Y.push_back(by[i]);
      X.push_back(ax[i]);
      X.push_back(bx[i]);
    }  
    
    func(Y,my,ay,by);
    func(X,mx,ax,bx);
    
    cout<<solve()<<endl;
  }
  return 0;
}