#include<iostream>
#include<set>
#include<numeric>

using namespace std;

int par[123456];

int find(int x){
  return (x==par[x])?x:find(par[x]);
}

void unite(int a,int b){
  par[find(a)]=find(b);
}

int main(){
  for(int N,M;cin>>N>>M,N|M;){
    iota(begin(par),end(par),0);
    for(int i=0;i<M;i++){
      int a,b;
      cin>>a>>b;
      a--;
      b--;
      unite(a,b);
    }
    set<int> s;
    for(int i=0;i<N;i++){
      s.insert(find(i));
    }
    int ans=1;
    for(int i=0;i<s.size();i++){
      ans=(ans*2)%1000000007;
    }
    cout<<(ans+!!M)%1000000007<<endl;
  }
}

    