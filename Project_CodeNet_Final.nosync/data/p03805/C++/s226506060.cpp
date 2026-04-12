#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

map<int,vector<int> > mp_e;

int func(int N,vector<int> visit){
  int v_size = visit.size();
  if(v_size==N){return 1;}
  
  int r = 0;
  vector<int> es = mp_e[visit.at(v_size-1)];
  REP(i,es.size()){
    int e = es.at(i);
    bool flag = true;
    REP(i,v_size){
      if(e==visit.at(i)){flag = false; break;}
    }
    if(flag){
	    visit.push_back(e);
    	r += func(N,visit);
    	visit.pop_back();
    }
  }
  return r;
}

int main(){
  int N,M; cin >>N>>M;
  
  for(int i=1;i<N+1;i++){
    mp_e[i] = {};
  }
  REP(i,M){
    int a,b; cin >>a >>b;
    mp_e[a].push_back(b);
    mp_e[b].push_back(a);
  }
  vector<int> start = {1};
  printf("%d\n",func(N,start));
}