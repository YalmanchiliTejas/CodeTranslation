#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  vector<int64_t>L;
  L.push_back(A[0]);
  for(int i=1;i<N;i++){
  auto itr=lower_bound(L.begin(),L.end(),A[i]);
    int k=distance(L.begin(),itr);
    if(k==0)
      L.insert(L.begin(),A[i]);
    else
      L.at(k-1)=A[i];
    
  
  }int ans=L.size();
  cout<<ans<<endl;
  
  
     return 0;
}