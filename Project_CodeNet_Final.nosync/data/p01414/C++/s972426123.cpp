#include<bits/stdc++.h>
#define INF (1e9)
#define N 16
#define M 4
using namespace std;
typedef pair<int,int> P;
typedef pair<P,P> P1;


int n, h[N], w[N];

string s[M];

int d[(1<<N)];

queue<P> q;

set<P1> Range;

void init(){

  for(int idx=0;idx<N;idx++){
    int y=idx/M, x=idx%M;
    
    for(int stamp=0;stamp<n;stamp++){
      
      for(int i=0;i<h[stamp];i++){
    
	for(int j=0;j<w[stamp];j++){

	  int miny=M,maxy=0,minx=M,maxx=0;
	  
	  for(int k=0;k<h[stamp];k++){
	
	    for(int l=0;l<w[stamp];l++){
	      
	      int ny=y-i+k, nx=x-j+l;
	      
	      if(ny<0||nx<0||M<=ny||M<=nx) continue;
	      
	      miny=min(miny,ny);

	      maxy=max(maxy,ny);
	      
	      minx=min(minx,nx);

	      maxx=max(maxx,nx);
	      
	    }
	    
	  }

	  Range.insert(P1(P(miny,maxy),P(minx,maxx)));
	  
	}

      }

    }
    
  }

  
}

char c[3]={'R','G','B'};

void mark(int cost,int S){
  
  auto ite=Range.begin();
  
  while(ite!=Range.end()){

    P1 t=(*ite);
    
    for(int k=0;k<3;k++){
      
      int nS=S;
    
      for(int i=t.first.first;i<=t.first.second;i++){
	for(int j=t.second.first;j<=t.second.second;j++){
	  
	  int p=i*M+j;
	
	  if(s[i][j]==c[k]) nS|=(1<<p);
	  else nS=nS&~(1<<p);
	  
	}
      }
      
      if(d[nS]>cost+1){
	
	d[nS]=cost+1;

	q.push(P(cost+1,nS));
	
      }
      
    }

    ite++;
  }
  
}

int bfs(){
  
  for(int i=0;i<(1<<N);i++) d[i]=INF;
  
  d[0]=0;
  
  q.push(P(0,0));
  
  while(!q.empty()){
    
    P t=q.front(); q.pop();
    
    int cost=t.first, S=t.second;
    
    if(S==(1<<N)-1) return cost;
    
    mark(cost,S);
    
  }

  return 0;
}


int main(){
  
  cin>>n;
  
  for(int i=0;i<n;i++) cin>>h[i]>>w[i];
  
  for(int i=0;i<M;i++) cin>>s[i];

  init();
  
  cout<<bfs()<<endl;
  
  return 0;
}