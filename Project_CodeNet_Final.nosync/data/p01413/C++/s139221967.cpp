#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<utility>
#include<cstdlib>
#include<algorithm>

using namespace std;

long long knapsack(int N,vector<pair<int,int> > v){
  vector<long long> dp(N+1);
  for(auto e:v){
    for(int i=e.first;i<dp.size();i++){
      dp[i]=max(dp[i],dp[i-e.first]+e.second);
    }
  }
  return dp.back();
}

int main(){
  int N,M,W,T;
  cin>>N>>M>>W>>T;
  map<string,int> V,P;
  for(int i=0;i<M;i++){
    string S;
    int v,p;
    cin>>S>>v>>p;
    V[S]=v;
    P[S]=p;
  }
  int L[7],X[7],Y[7];
  map<string,int> Q[7];
  for(int i=0;i<N;i++){
    cin>>L[i]>>X[i]>>Y[i];
    for(int j=0;j<L[i];j++){
      string R;
      int q;
      cin>>R>>q;
      Q[i][R]=q;
    }
  }
  vector<pair<int,int> > r;
  for(int i=1;i<1<<N;i++){
    vector<int> v;
    vector<pair<int,int> > vi;
    for(int j=0;j<N;j++){
      if(i>>j&1){
	v.push_back(j);
	for(auto e:Q[j]){
	  if(e.second<P[e.first]){
	    vi.emplace_back(V[e.first],P[e.first]-e.second);
	  }
	}
      }
    }
    int m=1<<29;
    do{
      int s=0;
      int x=0,y=0;
      for(auto e:v){
	s+=abs(X[e]-x)+abs(Y[e]-y);
	x=X[e];
	y=Y[e];
      }
      m=min(m,s+abs(x)+abs(y));
    }while(next_permutation(begin(v),end(v)));
    r.emplace_back(m,knapsack(W,vi));
  }
  cout<<knapsack(T,r)<<endl;
}