#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}


template <typename T>
vector<T> dijkstra(Int s,vector<vector<pair<Int, T> > > & G,T INF){
  using P = pair<T, Int>;
  Int n=G.size();
  vector<T> d(n,INF);
  vector<Int> b(n,-1);
  priority_queue<P,vector<P>,greater<P> > q;
  d[s]=0;
  q.emplace(d[s],s);
  while(!q.empty()){
    P p=q.top();q.pop();
    Int v=p.second;
    if(d[v]<p.first) continue;
    //cout<<v<<":"<<d[v]<<endl;
    for(auto& e:G[v]){
      Int u=e.first;
      T c=e.second;
      if(d[u]>d[v]+c){
	d[u]=d[v]+c;
	b[u]=v;
	q.emplace(d[u],u);
	//cout<<v<<"->"<<u<<":"<<c<<endl;
      }
    }
  }
  return d;
}


template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int a,b;
  cin>>a>>b;
  auto d=make_v<Int>(a,b);
  for(Int i=0;i<a;i++)
    for(Int j=0;j<b;j++)
      cin>>d[i][j];

  Int N=71;
  Int sz=N*4;
  Int s=sz++,t=sz++,z=sz++;
  auto idx=[&](Int x){return x;};
  auto idy=[&](Int y){return N+y;};
  auto idx2=[&](Int x){return N*2+x;};
  auto idy2=[&](Int y){return N*3+y;};
  using P = pair<Int, Int>;
  vector<vector<P> > G(sz);

  vector<Int> C(sz,0),D(sz,0);
  auto E=make_v<Int>(sz,sz);
  auto F=make_v<Int>(sz,sz);
  fill_v(E,0);
  fill_v(F,0);
  
  const Int INF = 1e5;
  
  for(Int i=0;i<a;i++){
    for(Int j=0;j<b;j++){
      for(Int k=0;k<N;k++){
	chmax(C[k],d[i][j]-(i+1)*k);
	chmax(D[k],d[i][j]-(j+1)*k);
      }
    }
  }
  
  for(Int i=0;i<a;i++){
    for(Int j=0;j<b;j++){
      for(Int k=0;k<N;k++){
	for(Int l=0;l<N;l++){
	  chmax(E[k][l],d[i][j]-((i+1)*k+(j+1)*(N-(l+1))));
	  chmax(F[k][l],d[i][j]-((j+1)*k+(i+1)*(N-(l+1))));
	}
      }
    }
  }
  
  G[s].emplace_back(z,0);
  G[s].emplace_back(idx(0),0);
  G[s].emplace_back(idy(0),0);
  G[idx2(N-1)].emplace_back(t,0);
  G[idy2(N-1)].emplace_back(t,0);
  
  for(Int k=0;k<N;k++){
    G[idx(k)].emplace_back(t,C[k]);
    G[idy(k)].emplace_back(t,D[k]);
     
    for(Int l=0;l<N;l++){
      G[idx(k)].emplace_back(idy2(l),E[k][l]);
      G[idy(k)].emplace_back(idx2(l),F[k][l]);      
    }
  }
  
  bool flg=1;
  for(Int i=0;i<a;i++){
    for(Int j=0;j<b;j++){
      auto T=G;
      for(Int k=1;k<N;k++){
	T[idx(k-1)].emplace_back(idx(k),i+1);
	T[idy(k-1)].emplace_back(idy(k),j+1);
	T[idx2(k-1)].emplace_back(idx2(k),i+1);
	T[idy2(k-1)].emplace_back(idy2(k),j+1);
      }
      Int dist=dijkstra(s,T,INF)[t];
      //cout<<dist<<" "<<d[i][j]<<endl;
      flg&=(dist==d[i][j]);
      assert(dist>=d[i][j]);
    }
  }
  
  if(!flg){
    cout<<"Impossible"<<endl;
    return 0;
  }
  
  //assert(0);
  vector<vector<Int> > X(sz),Y(sz);
  for(Int i=1;i<N;i++){
    X[idx(i-1)].emplace_back(idx(i));
    Y[idy(i-1)].emplace_back(idy(i));
    X[idx2(i-1)].emplace_back(idx2(i));
    Y[idy2(i-1)].emplace_back(idy2(i));
  }
  
  assert(sz<=300);
  auto cnt=make_v<Int>(sz,sz);
  fill_v(cnt,0);
  for(Int v=0;v<sz;v++){
    for(auto p:G[v]) assert(v!=p.first);
    for(auto u:X[v]) assert(v!=u);
    for(auto u:Y[v]) assert(v!=u);
    
    for(auto p:G[v]) cnt[v][p.first]++;
    for(auto u:X[v]) cnt[v][u]++;
    for(auto u:Y[v]) cnt[v][u]++;
    for(Int u=0;u<sz;u++) assert(cnt[v][u]<=1);

    for(auto p:G[v]) assert(0<=p.second&&p.second<=100);
  }
  
  Int es=0;
  for(Int v=0;v<sz;v++) es+=X[v].size()+Y[v].size()+G[v].size();
  cout<<"Possible"<<endl;
  cout<<sz<<" "<<es<<endl;
  for(Int v=0;v<sz;v++){
    for(auto p:G[v]) cout<<v+1<<" "<<p.first+1<<" "<<p.second<<endl;
    for(Int u:X[v]) cout<<v+1<<" "<<u+1<<" X"<<endl;
    for(Int u:Y[v]) cout<<v+1<<" "<<u+1<<" Y"<<endl;
  }
  cout<<s+1<<" "<<t+1<<endl;
  return 0;
}
