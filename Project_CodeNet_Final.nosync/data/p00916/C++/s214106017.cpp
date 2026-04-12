#include<bits/stdc++.h>
using namespace std;
struct rect{
  int l,t,r,b;
  rect(){}
  rect(int l,int t,int r,int b):l(l),t(t),r(r),b(b){}
};
typedef pair<int,int> P;
int main(){
  int n;
  while(cin>>n,n){
    int i,j,k=0,a,b,c,f,inf=1<<25;
    vector<int> xs,ys;
    vector<rect> v;
    rect r;
    for(i=0;i<n;i++){
      cin>>r.l>>r.t>>r.r>>r.b;
      xs.push_back(r.l);
      xs.push_back(r.r);
      ys.push_back(r.t);
      ys.push_back(r.b);
      v.push_back(r);
    }
    xs.push_back(-inf);xs.push_back(inf);
    ys.push_back(-inf);ys.push_back(inf);
    sort(xs.begin(),xs.end());
    sort(ys.begin(),ys.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    ys.erase(unique(ys.begin(),ys.end()),ys.end());
    map<int,int> xm,ym;
    for(i=0;i<xs.size();i++) xm[xs[i]]=i;
    for(i=0;i<ys.size();i++) ym[ys[i]]=i;
    bool ex[xs.size()+1][ys.size()+1],ey[xs.size()+1][ys.size()+1];
    memset(ex,0,sizeof(ex));
    memset(ey,0,sizeof(ey));
    for(i=0;i<n;i++){
      r=v[i];
      for(j=xm[r.l];j<xm[r.r];j++) ex[j][ym[r.b]]=ex[j][ym[r.t]]=1;
      for(j=ym[r.b];j<ym[r.t];j++) ey[xm[r.l]][j]=ey[xm[r.r]][j]=1;
    }
    bool u[xs.size()+1][ys.size()+1];
    memset(u,0,sizeof(u));
    for(i=0;i<xs.size();i++){
      for(j=0;j<ys.size();j++){
	if(u[i][j]) continue;
	queue<P> q;
	q.push(P(i,j));
	while(!q.empty()){
	  a=q.front().first;b=q.front().second;q.pop();
	  if(a<0||a>=xs.size()||b<0||b>=ys.size()||u[a][b]) continue;
	  u[a][b]=1;
	  if(!ex[a][b]) q.push(P(a,b-1));
	  if(!ex[a][b+1]) q.push(P(a,b+1));
	  if(!ey[a][b]) q.push(P(a-1,b));
	  if(!ey[a+1][b]) q.push(P(a+1,b));
	}
	k++;
      }
    }
    cout << k << endl;
  }
  return 0;
}