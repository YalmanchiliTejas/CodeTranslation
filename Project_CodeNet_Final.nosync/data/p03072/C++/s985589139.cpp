#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, f=1;
  cin>>N;
  vector<int> vec(N);
  for(int i=0; i<N; i++) {
    cin>>vec.at(i);
    }
  for(int i=1; i<N;i++){
    for(int j=0;j<i;j++){
      if(vec.at(i)-vec.at(j)<0)break;
      else if(i==j+1)f++;
    }
  }
  cout<<f<<endl;
} 