#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string s;
  cin>>N>>s;
  vector<int> animal={1,-1};
  vector<int> ss(N);
  bool flag=false;
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      ss.at(0)=animal.at(i);
      ss.at(1)=animal.at(j);
      for(int k=1;k<N-1;k++){
        int x;
        if(s.at(k)=='o'){
          x=1;
        }else{
          x=-1;
        }
        ss.at(k+1)=x*ss.at(k-1)*ss.at(k);
      }
      int x;
      if(s.at(N-1)=='o'){
        x=1;
      }else{
        x=-1;
      }
      int y;
      if(s.at(0)=='o'){
        y=1;
      }else{
        y=-1;
      }
      if(ss.at(N-2)*ss.at(N-1)*x==ss.at(0)&&ss.at(N-1)*ss.at(0)*y==ss.at(1)){
        flag=true;
        break;
      }
    }
    if(flag){
      break;
    }
  }
  
  if(flag){
    for(int i=0;i<N;i++){
      if(ss.at(i)==1){
        cout<<'S';
      }else{
        cout<<'W';
      }
    }
    cout<<endl;
  }else{
    cout<<-1<<endl;
  }
}
  
      