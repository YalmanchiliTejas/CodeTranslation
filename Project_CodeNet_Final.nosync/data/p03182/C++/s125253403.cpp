#include <bits/stdc++.h>

int N;
int M;

struct segtree{
  
  int n;
  long long v[1000000];
  long long lazy[1000000];
  
  segtree(int n_){
    n=1;
    while(n<n_)n*=2;
    for(int i=0;i<2*n-1;++i){
      v[i]=0;
      lazy[i]=0;
    }
  }

  long long query(int a,int b,long long add){
    return query(0,n,a,b,0,add);
  }

  long long push(int k){
    v[k]+=lazy[k];
    if(2*k+2<2*n-1){
      lazy[2*k+1]+=lazy[k];
      lazy[2*k+2]+=lazy[k];
    }
    lazy[k]=0;
  }
  
  long long query(int l,int r,int a,int b,int k,long long add){
    push(k);
    if(r<=a||b<=l){
      return -(1LL<<60);
    }else if(a<=l&&r<=b){
      lazy[k]+=add;
      push(k);
      return v[k];
    }else{
      long long vl=query(l,(l+r)/2,a,b,2*k+1,add);
      long long vr=query((l+r)/2,r,a,b,2*k+2,add);
      v[k]=std::max(v[2*k+1],v[2*k+2]);
      return std::max(vl,vr);
    }
  }
  
};

int main(){
  
  std::cin>>N;
  std::cin>>M;
  
  std::vector<int> dst[N];
  std::vector<long long> add[N];
  for(int i=0;i<M;++i){
    int l,r;
    long long a;
    std::cin>>l>>r>>a;
    --l;
    --r;
    dst[r].push_back(l);
    add[r].push_back(a);
  }
  
  segtree seg(N);
  for(int i=0;i<N;++i){
    long long sum=0;
    for(int j=0;j<dst[i].size();++j){
      sum+=add[i][j];
    }
    seg.query(i,i+1,sum+std::max(0LL,seg.query(0,i,0)));
    for(int j=0;j<dst[i].size();++j){
      seg.query(dst[i][j],i,add[i][j]);
    }
  }

  std::cout<<std::max(0LL,seg.query(0,N,0))<<std::endl;


  return 0;
}
