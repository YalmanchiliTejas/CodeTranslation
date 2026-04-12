#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;

struct Dinic{
  const int INF=1<<28;
  
  struct edge {
    int to,cap,rev;
    edge(){}
    edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}
  };

  int n;
  vector<vector<edge> > G;
  vector<map<int,int> > M;
  vector<int> level,iter;

  Dinic(){}
  Dinic(int sz):n(sz),G(n),M(n),level(n),iter(n){}
  
  void add_edge(int from,int to,int cap){
    M[from][to]=G[from].size();
    M[to][from]=G[to].size();
    G[from].push_back(edge(to,cap,G[to].size()));
    // undirected
    //G[to].push_back(edge(from,cap,G[from].size()-1));
    // directed
    G[to].push_back(edge(from,0,G[from].size()-1));
  }
  
  void bfs(int s){
    fill(level.begin(),level.end(),-1);
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty()){
      int v=que.front();que.pop();
      for(int i=0;i<(int)G[v].size();i++){
        edge &e = G[v][i];
        if(e.cap>0&&level[e.to]<0){
          level[e.to]=level[v]+1;
          que.push(e.to);
        }
      }
    }
  }
  
  int dfs(int v,int t,int f){
    if(v==t) return f;
    for(int &i=iter[v];i<(int)G[v].size();i++){
      edge &e=G[v][i];
      if(e.cap>0&&level[v]<level[e.to]){
        int d = dfs(e.to,t,min(f,e.cap));
	     if(d>0){
	       e.cap-=d;
	       G[e.to][e.rev].cap+=d;
	       return d;
	     }
      }
    }
    return 0;
  }
  
  int flow(int s,int t,int lim){
    int fl=0;
    for(;;){
      bfs(s);
      if(level[t]<0||lim==0) return fl;
      fill(iter.begin(),iter.end(),0);
      int f;
      while((f=dfs(s,t,lim))>0){
	     fl+=f;
	     lim-=f;
      }
    }
  }

  int flow(int s,int t){
    return flow(s,t,INF);
  }

  //cap==1 only
  bool back_edge(int s,int t,int from, int to){
    for(int i=0;i<(int)G[from].size();i++) {
      edge& e=G[from][i];
      if(e.to==to) {
        if(e.cap==0&&flow(from,to,1)==0) {
          flow(from,s,1);
          flow(t,to,1);
          return 1;
        }
      }
    }
    return 0;
  }
};

int A,B,C,D,NB,NC,ND,x,y,z;

int main(){
	while(cin>>A>>B>>C>>D>>NB>>NC>>ND,A!=-1){
		Dinic DIN(500);
		map<int,int>Ai,Bi,Ci,Di,Bp,Cp;  // number -> id;
		int id=0;
		r(i,A)Ai[i]=id++;
		r(i,B)Bp[i]=id++;
		r(i,B)Bi[i]=id++;
		r(i,C)Cp[i]=id++;
		r(i,C)Ci[i]=id++;
		r(i,D)Di[i]=id++;
		r(i,B){
			cin>>x;
			while(x--){
				cin>>y;
				y--;
				DIN.add_edge(Ai[y],Bp[i],1);
			}
		}
		r(i,C){
			cin>>x;
			while(x--){
				cin>>y;
				y--;
				DIN.add_edge(Bi[y],Cp[i],1);
			}
		}
		r(i,D){
			cin>>x;
			while(x--){
				cin>>y;
				y--;
				DIN.add_edge(Ci[y],Di[i],1);
			}
		}
		r(i,B){
			DIN.add_edge(Bp[i],Bi[i],1);
		}
		r(i,C){
			DIN.add_edge(Cp[i],Ci[i],1);
		}

		r(i,A)r(j,C){
			DIN.add_edge(Ai[i],id,1);
			if(!i)DIN.add_edge(id+1,Cp[j],1);
		}
		DIN.add_edge(id,id+1,NB); id+=2;
		r(i,B)r(j,D){
			DIN.add_edge(Bi[i],id,1);
			if(!i)DIN.add_edge(id+1,Di[j],1);
		}
		DIN.add_edge(id,id+1,NC); id+=2;
		int source=id,sink=id+1; id+=2;
		r(j,C){
			DIN.add_edge(Ci[j],id,1);
		}
		DIN.add_edge(id,sink,ND);
		r(i,A)DIN.add_edge(source,i,1);
		r(i,D)DIN.add_edge(Di[i],sink,1);
		cout<<DIN.flow(source,sink)<<endl;
	}
}
