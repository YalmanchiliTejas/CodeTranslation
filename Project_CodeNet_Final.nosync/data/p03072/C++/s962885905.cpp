#include<bits/stdc++.h>
using namespace std;
int main(){
  int N=0;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  int ans=0;
  int maxheight=-1;
  for(int i=0;i<N;i++){
    if(maxheight<=A.at(i)){
      ans++;
      maxheight=A.at(i);
    }
  }
  cout<<ans<<endl;
}
