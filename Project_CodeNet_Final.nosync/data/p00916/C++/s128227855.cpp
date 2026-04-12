#include<bits/stdc++.h>
using namespace std;

int n,l[51],t[51],r[51],b[51];
int area[300][300];
int nx[4]={-1,0,1,0};
int ny[4]={0,1,0,-1};
int h,w;

bool in(int a,int b){
  if(a<0 || b<0 || a>=h || b>=w)return false;
  return true;
}

void dfs(int a,int b,int num){
  for(int i=0;i<4;i++){
    int A=a+ny[i],B=b+nx[i];
    if(!in(A,B))continue;
    if(area[A][B]==0){
      area[A][B]=num;
      dfs(A,B,num);
    }
  }
  return;
}

int main()
{
  while(1){
    cin>>n;
    if(n==0)break;
    vector<int> x,y;
    for(int i=0;i<300;i++)for(int j=0;j<300;j++)area[i][j]=0;
    for(int i=0;i<n;i++){
      cin>>l[i]>>t[i]>>r[i]>>b[i];
      x.push_back(l[i]);
      x.push_back(r[i]);
      y.push_back(t[i]);
      y.push_back(b[i]);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    map<int,int> X,Y;
    int num=1;
    for(int i=0;i<x.size();i++){
      if(X.find(x[i])==X.end()){
	X[x[i]]=num; 
	num+=2;
      }
    }
    num=1;
    for(int i=0;i<y.size();i++){
      if(Y.find(y[i])==Y.end()){
	Y[y[i]]=num;
	num+=2;
      }
    }
    w=X.size()*2+1;
    h=Y.size()*2+1;
    for(int k=0;k<n;k++){
      int L=X[l[k]],R=X[r[k]],T=Y[t[k]],B=Y[b[k]];
      for(int i=L;i<=R;i++){
	area[T][i]=-1;
	area[B][i]=-1;
      }
      for(int i=B;i<=T;i++){
	area[i][L]=-1;
	area[i][R]=-1;
      }
    } 
    
    int ans=0;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	if(area[i][j]==0){
	  ans++;
	  area[i][j]=ans;
	  dfs(i,j,ans);
	}
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}