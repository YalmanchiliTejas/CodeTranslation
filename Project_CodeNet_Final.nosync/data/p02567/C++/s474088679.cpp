#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll=long long;
using Graph=vector<vector<int>>;
using pp=pair<ll,pair<ll,ll>>;
#define MAX 1000000
#define MOD 998244353
#define INF 1000000000000000000

vector<int> tree;
int n=1;
int solve_max(int a,int b,int i,int left,int right){
  if(b<=left||right<=a){
    return 0;
  }
  if(a<=left&&right<=b){
    return tree[i];
  }
  return max(solve_max(a,b,2*i+1,left,(left+right)/2),solve_max(a,b,2*i+2,(left+right)/2,right));
}

void update(int k,int x){
  int i=n-1+k;
  tree[i]=x;
  while(i>0){
    i=(i-1)/2;
    tree[i]=max(tree[2*i+1],tree[2*i+2]);
  }
}

int solve_min_j(int a,int b,int V){
  if(solve_max(a,b,0,0,n)<V){
    return b;
  }
  while(a+1<b){
    int c=(a+b)/2;
    int x=solve_max(a,c,0,0,n);
    if(x>=V){
      b=c;
    }else{
      a=c;
    }
  }
  return a;
}



int main(){
  int N,Q;
  cin>>N>>Q;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }

  while(n<N){
    n<<=1;
  }
  tree.resize(2*n-1.0);
  for(int i=0;i<N;i++){
    tree[i+n-1]=A[i];
  }
  for(int i=n-2;i>=0;i--){
    tree[i]=max(tree[2*i+1],tree[2*i+2]);
  }

  vector<int> ans;
  for(int i=0;i<Q;i++){
    int T;
    cin>>T;
    if(T==1){
      int a,v;
      cin>>a>>v;
      a--;
      update(a,v);
    }else if(T==2){
      int L,R;
      cin>>L>>R;
      L--;
      ans.push_back(solve_max(L,R,0,0,n));
    }else{
      int X,V;
      cin>>X>>V;
      X--;
      ans.push_back(solve_min_j(X,N,V)+1);
    }
  }

  for(auto x:ans){
    cout<<x<<endl;
  }
}
