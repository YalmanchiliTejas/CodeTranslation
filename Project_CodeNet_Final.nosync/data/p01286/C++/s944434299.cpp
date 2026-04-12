#include<bits/stdc++.h>
using namespace std;
using Int = long long;

struct Fordfulkerson{
  static const Int INF = 1 << 28;
  struct edge{
    Int to,cap,rev;
    edge(){}
    edge(Int to,Int cap,Int rev):to(to),cap(cap),rev(rev){}
  };
  
  vector<vector<edge> > G;
  vector<Int> used;
  
  Fordfulkerson(){}
  Fordfulkerson(Int V){init(V);}
  
  void init(Int V){
    for(Int i=0;i<(Int)G.size();i++) G[i].clear();
    G.clear();
    used.clear();
    G.resize(V);
    used.resize(V);
  }
  
  void add_edge(Int from,Int to,Int cap){
    //cout<<from<<" "<<to<<endl;
    G[from].push_back(edge(to,cap,G[to].size()));
    // undirected
    //G[to].push_back(edge(from,cap,G[from].size()-1));
    // directed
    G[to].push_back(edge(from,0,G[from].size()-1));
  }
 
  Int dfs(Int v,Int t,Int f){
    if(v==t) return f;
    used[v]=true;
    for(Int i=0;i<(Int)G[v].size();i++){
      edge &e = G[v][i];
      if(!used[e.to] && e.cap > 0 ){
	Int d=dfs(e.to,t,min(f,e.cap));
	if(d>0){
	  e.cap-=d;
	  G[e.to][e.rev].cap+=d;
	  return d;
	}
      } 
    }
    return 0;
  }
 
  Int max_flow(Int s,Int t,Int lim=INF){
    Int flow=0;
    for(;;){
      fill(used.begin(),used.end(),0);
      Int f=dfs(s,t,lim);
      if(f==0) return flow;
      flow+=f;
      lim-=f;
    }
  }
};



signed main(){
  Int h,w,c,m,nw,nc,nm;
  while(cin>>h>>w>>c>>m>>nw>>nc>>nm,h>=0){
    Int base=h+w+c+m;
    Int beet=base*2;
    Int s1=beet++;
    Int s2=beet++;
    Int s3=beet++;
    Int s4=beet++;
    Int t1=beet++;
    Int t2=beet++;
    Int t3=beet++;
    Int t4=beet++;
    //cout<<beet<<endl;
    
    Fordfulkerson dinic(beet);
    auto getH=[&](Int x,Int y){assert(0<=x&&x<h);return y*base+x;};
    auto getW=[&](Int x,Int y){assert(0<=x&&x<w);return y*base+h+x;};
    auto getC=[&](Int x,Int y){assert(0<=x&&x<c);return y*base+h+w+x;};
    auto getM=[&](Int x,Int y){assert(0<=x&&x<m);return y*base+h+w+c+x;};

    for(Int i=0;i<base;i++) dinic.add_edge(i,base+i,1);
    
    for(Int i=0;i<w;i++){
      Int k;
      cin>>k;
      for(Int j=0;j<k;j++){
	Int x;
	cin>>x;
	x--;
	dinic.add_edge(getW(i,1),getH(x,0),1);
      }
    }
    for(Int i=0;i<c;i++){
      Int k;
      cin>>k;
      for(Int j=0;j<k;j++){
	Int x;
	cin>>x;
	x--;
	dinic.add_edge(getC(i,1),getW(x,0),1);
      }
    }
    for(Int i=0;i<m;i++){
      Int k;
      cin>>k;
      for(Int j=0;j<k;j++){
	Int x;
	cin>>x;
	x--;
	dinic.add_edge(getM(i,1),getC(x,0),1);
      }
    }

    //cout<<"x"<<endl;
    
    //*/
    for(Int i=0;i<w;i++)
      dinic.add_edge(s1,getW(i,0),1);
    for(Int i=0;i<h;i++)
      dinic.add_edge(getH(i,1),t1,1);

    
    for(Int i=0;i<m;i++)
      dinic.add_edge(s2,getM(i,0),1);
    for(Int i=0;i<c;i++)
      dinic.add_edge(getC(i,1),t2,1);

    
    for(Int i=0;i<c;i++)
      dinic.add_edge(s3,getC(i,0),1);
    for(Int i=0;i<h;i++)
      dinic.add_edge(getH(i,1),t3,1);
    //*/
    
    for(Int i=0;i<m;i++)
      dinic.add_edge(s4,getM(i,0),1);
    for(Int i=0;i<h;i++)
      dinic.add_edge(getH(i,1),t4,1);

    

    Int B=dinic.max_flow(s1,t1,min(nc,m));
    Int A=dinic.max_flow(s2,t2,min({nw,h-B,m-B}));
    Int D=dinic.max_flow(s3,t3,min({nm,h-(A+B),w-(B),c-(A)}));
    Int C=dinic.max_flow(s4,t4,min({h-(A+B+D),w-(B+D),c-(A+D),m-(A+B)}));
    Int E=min({nw-A,nm-D,h-(A+B+C+D),c-(A+C+D)});


    //cout<<h<<" "<<w<<" "<<c<<" "<<m<<":"<<nw<<" "<<nc<<" "<<nm<<endl;
    //cout<<A<<" "<<B<<" "<<C<<" "<<D<<" "<<E<<endl;
    
    assert(A+B+C+D+E<=h);
    assert(B+C+D<=w);
    assert(A+E<=nw);
    assert(A+C+D+E<=c);
    assert(B<=nc);
    assert(A+B+C<=m);
    assert(D+E<=nm);
    
    cout<<A+B+C+D+E<<endl;
    //break;
  }
  return 0;
}