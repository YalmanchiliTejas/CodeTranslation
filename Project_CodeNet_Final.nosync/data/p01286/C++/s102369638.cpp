#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

#define MAX 500
#define INF (1 << 21)

int cap[MAX][MAX];
bool visited[MAX];
int parent[MAX];
int flow[MAX][MAX];
int layer[MAX];

void make_layer(int n,int s,int t){
  queue<int> Q;
  Q.push(s);
  layer[s]=0;
  while(!Q.empty()){
    int now = Q.front();
    Q.pop();
    rep(i,n){
      if ( cap[now][i]-flow[now][i]>0 && layer[i]==-1){
	layer[i]=layer[now]+1;
	Q.push(i);
      }
    }
  }
}

int augment(int now,int t,int n,int f){
  if (now == t || f == 0)return f;
  if (visited[now])return 0;
  visited[now]=true;
  rep(i,n){
    if (layer[now]<layer[i]){
      int tmp = augment(i,t,n,min(f,cap[now][i]-flow[now][i]));
      if (tmp > 0){
	flow[now][i]+=tmp;
	flow[i][now]=-flow[now][i];
	visited[now]=false;
	return tmp;
      }
    }
  }
  return 0;
}


int dinic(int n,int s,int t){
  int ansflow=0;
  bool flag=true;
  rep(i,n)rep(j,n)flow[i][j]=0;
  while(flag){
    fill(layer,layer+n,-1);
    fill(visited,visited+n,false);
    flag=false;
    make_layer(n,s,t);
    if (layer[t]==-1)break;
    
    for(int f=1;f;flag=true){
      f = augment(s,t,n,INF);
      if ( f==0)break;
      ansflow+=f;
    }
  }
  return ansflow;
}


#define SSOURCE 0
#define Nwin    1
#define Nwout   2
#define Ncin    3
#define Ncout   4
#define Nmin    5
#define Nmout   6
#define SSINK   7

#define IN(i)  (2*i)
#define OUT(i) (2*i+1)

main(){
  int h,w,c,m,nw,nc,nm;
  while(cin>>h>>w>>c>>m>>nw>>nc>>nm && h != -1){
    int n = 8+2*h+2*w+2*c+2*m;
    int He =8;
    int Wa =He+2*h;
    int Cl =Wa+2*w;
    int Ma =Cl+2*c;
    rep(i,n)rep(j,n)cap[i][j]=0;
    cap[Nwin][Nwout]=nw;
    cap[Ncin][Ncout]=nc;
    
    cap[Nmin][Nmout]=nm;
    cap[Nmout][SSINK]=INF;

    rep(i,h){
      cap[SSOURCE][He+IN(i)]=1;
      cap[He+IN(i)][He+OUT(i)]=1;
      cap[He+OUT(i)][Nwin]=1;
    }
    
    rep(i,w){
      int num;
      cin>>num;
      cap[Wa+IN(i)][Wa+OUT(i)]=1;
      cap[Wa+IN(i)][Ncin]=1;
      rep(j,num){
	int t;
	cin>>t;
	t--;
	cap[He+OUT(t)][Wa+IN(i)]=1;
      }
    }
    
    rep(i,c){
      int num;
      cin>>num;
      cap[Nwout][Cl+IN(i)]=1;
      cap[Cl+IN(i)][Cl+OUT(i)]=1;
      cap[Cl+OUT(i)][Nmin]=1;
      rep(j,num){
	int t;
	cin>>t;
	t--;
	cap[Wa+OUT(t)][Cl+IN(i)]=1;
      }
    }
    
    
    
    rep(i,m){
      int num;
      cin>>num;
      cap[Ncout][Ma+IN(i)]=1;
      cap[Ma+IN(i)][Ma+OUT(i)]=1;
      cap[Ma+OUT(i)][SSINK]=1;
      rep(j,num){
	int t;
	cin>>t;
	t--;
	cap[Cl+OUT(t)][Ma+IN(i)]=1;
      }
    }
    
    

    cout << dinic(n,SSOURCE,SSINK) << endl;


  
  }
  
}