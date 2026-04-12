#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  multiset<int64_t> S;
  vector<int64_t> A(N);
  for(int i=0;i<N;++i){
    cin>>A[i];
  }

  for(int i=0;i<N;++i){
    if(S.empty()){
      S.insert(A[i]);
    }
    else{
      auto iter=S.begin();
      int64_t B=*iter;
      if(B>=A[i]){
        S.insert(A[i]);
      }
      else{
        auto iter=S.lower_bound(A[i]);
        --iter;
        S.erase(iter);
        S.insert(A[i]);
      }
    }
  }

  cout<<S.size()<<endl;
}