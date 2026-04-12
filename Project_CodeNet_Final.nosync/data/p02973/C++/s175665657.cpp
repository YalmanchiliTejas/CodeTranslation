#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<int>A(N);for(int i=0;i<N;i++)cin>>A[i];
  deque<int>cols(1,-1);
  for(int i=0;i<N;i++){
    auto itr=lower_bound(cols.begin(),cols.end(),A[i]);
    if(itr==cols.begin())cols.push_front(A[i]);
    else {itr--;*itr=A[i];}
  }
  cout<<cols.size();
}

