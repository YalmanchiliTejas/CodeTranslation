#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,sum=0;
  cin >>N;
  
  vector<int> h(N);
  
  for (int i=0;i<N;i++){
    cin>>h.at(i);
  }
  for (int i=1;i<N;i++){
    int x=0;
    for (int j=0;j<i;j++){
      if(h.at(i)>=h.at(j)){
        x++;
      }
    }
    if (x==i){
      sum++;
    }
  }
  cout <<sum+1<<endl;
}