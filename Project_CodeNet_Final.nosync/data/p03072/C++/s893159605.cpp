#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

int main() {
  int N;
  cin>>N;
  
  vector<int> h(N);
  for(int i=0;i<N;++i){
    cin>>h[i];
  }
  
  int count=0;
  
  for(int i=1;i<N;++i){
    int x=0;
    for(int j=0;j<i;++j){
      x=max(x,h[j]);
    }
    if(x<=h[i])
      ++count;
  }
  
  cout<<count+1<<endl;
}
