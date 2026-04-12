#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,m,kanou,ans;
  ans=0;
  cin>>n>>m;
  vector<pair<int,int> > vec(m);
  vector<int> nagare(n);
  for(int i=0; i<m; i++){
    cin>>vec.at(i).first;
    cin>>vec.at(i).second;
  }
  for(int i=0; i<n; i++){
    nagare.at(i)=i+1;
  }
  do {
    kanou=1;
    for(int i=0; i<n-1; i++){
      if(nagare.at(0)!=1){
        kanou=0;
        break;
      }
      for(int j=0; j<m; j++){
        if(nagare.at(i)==vec.at(j).first && nagare.at(i+1)==vec.at(j).second){
          break;
        }
        if(nagare.at(i)==vec.at(j).second && nagare.at(i+1)==vec.at(j).first){
          break;
        }
        if(j==m-1){
          kanou=0;
        }
      }
      if(kanou==0){
        break;
      }
    }
    if(kanou==1){
     
      
      ans=ans+1;
    }
  }
  while(next_permutation(nagare.begin(),nagare.end() ) );
  cout<<ans;
}
    