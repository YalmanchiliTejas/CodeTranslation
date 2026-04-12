#include <cstdio>
#include <vector>
#include <algorithm>
#include <stdint.h>

const int64_t INF=1e15+7;

std::vector<std::pair<int64_t,int64_t> > delta[200005];

int64_t st[800005];
int64_t lazy[800005];

void push(int64_t w,int64_t L,int64_t R){
  if(R-L>1){
    lazy[w<<1]+=lazy[w];
    lazy[w<<1|1]+=lazy[w];
  }
  st[w]+=lazy[w];
  lazy[w]=0;
}

void pull(int64_t w,int64_t L,int64_t R){
  st[w]=std::max(st[w<<1],st[w<<1|1]);
}

void update(int64_t w,int64_t L,int64_t R,int64_t a,int64_t b,int64_t v){
  push(w,L,R);
  if(b<=L||a>=R) return;
  if(a<=L&&b>=R){
    lazy[w]+=v;
    push(w,L,R);
  }else{
    int64_t M=(L+R)/2;
    update(w<<1,L,M,a,b,v);
    update(w<<1|1,M,R,a,b,v);
    pull(w,L,R);
  }
}

int64_t query(int64_t w,int64_t L,int64_t R,int64_t a,int64_t b){
  push(w,L,R);
  if(b<=L||a>=R) return -INF;
  if(a<=L&&b>=R){
    return st[w];
  }else{
    int64_t M=(L+R)/2;
    return std::max(query(w<<1,L,M,a,b),
		    query(w<<1|1,M,R,a,b));
  }
}

int64_t dp[200005];

int main(){
  int64_t N,M;
  scanf("%ld %ld",&N,&M);
  for(int64_t i=0;i<M;i++){
    int64_t L,R,A;
    scanf("%ld %ld %ld",&L,&R,&A);
    delta[L].emplace_back(L,A);
    delta[R+1].emplace_back(L,-A);
  }
  for(int64_t i=1;i<=N+1;i++){
    for(auto p:delta[i]){
      update(1,0,N+1,0,p.first,p.second);
    }
    dp[i]=query(1,0,N+1,0,i);
    update(1,0,N+1,i,i+1,dp[i]);
  }
  printf("%ld\n",dp[N+1]);
  return 0;
}
