#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int>rec(N);
  for(int i=0;i<N;i++){
    cin>>rec.at(i);
  }
  int count=1;
  for(int i=1;i<N;i++){
    bool frag=true;
    for(int j=0;j<i;j++){
      if(rec.at(i)<rec.at(j)){
        frag=false;
        break;
      }
      else{
      }
    }
    if(frag==false){
    }
    else{
      count=count+1;
    }
  }
  cout<<count<<endl;
}
    