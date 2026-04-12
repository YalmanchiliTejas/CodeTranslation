#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
#define MAX 100005
int N;
int x[100000],y[100000];

int d[100000];
int visited[MAX];
int vdx[MAX];
int vdy[MAX];

vector<int> X,Y;
map< int, vector<int> > gx, gy;

int main(){
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>x[i]>>y[i];
    X.push_back(x[i]);
    Y.push_back(y[i]);
    gx[ x[i] ].push_back(i);
    gy[ y[i] ].push_back(i);
    d[i]=1e9+1;
  }
  sort(X.begin(),X.end());
  X.erase( unique(X.begin(),X.end()) , X.end());
  sort(Y.begin(),Y.end());
  Y.erase( unique(Y.begin(),Y.end()) , Y.end());

  
  priority_queue< P , vector<P> , greater<P> > Q;
  d[0]=0;
  Q.push(P(0,0));
  
  while(!Q.empty()){
    P p=Q.top();Q.pop();
    int pos=p.second;
    if(visited[pos])continue;
    visited[pos]=true;

    int xid=lower_bound(X.begin(),X.end(), x[pos])-X.begin();
    if( vdx[xid]==0 ){
      vdx[xid]=1;
      for(int to:gx[ x[pos] ]){
        if(d[to]>0 && visited[to]==0){
          d[to]=0;
          Q.push( P(d[to],to) );
        }
      }
    }
    
    for(int nxid=xid-1;nxid<=xid+1;nxid+=2){
      if( nxid<0 || (int)X.size()<=nxid)continue;
      int to=gx[ X[nxid] ][0];
      int di=abs( X[nxid]-X[xid] );
      if( visited[to]==0 && di<d[to]){
        d[to]=di;
        Q.push( P(d[to],to) );
      }
    }
    
    int yid=lower_bound(Y.begin(),Y.end(), y[pos])-Y.begin();
    if( vdy[yid]==0 ){
      vdy[yid]=1;
      for(int to:gy[ y[pos] ]){
        if(d[to]>0 && visited[to]==0){
          d[to]=0;
          Q.push( P(d[to],to) );
        }
      }
    }

    for(int nyid=yid-1;nyid<=yid+1;nyid+=2){
      if( nyid<0 || (int)Y.size()<=nyid)continue;
      int to=gy[ Y[nyid] ][0];
      int di=abs( Y[nyid]-Y[yid] );
      if( visited[to]==0 && di<d[to]){
        d[to]=di;
        Q.push( P(d[to],to) );
      }
    }
  }
  long long ans=0;
  for(int i=0;i<N;i++){
    ans+= (long long)d[i];
  }
  cout<<ans<<endl;
  return 0;
}
