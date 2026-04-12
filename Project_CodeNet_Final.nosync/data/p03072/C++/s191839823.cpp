#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  vector<int> H;
  cin>>N;
  
  for(int i=0;i<N;i++){
    int x;
    cin>>x;
    H.push_back(x);
  }
  
  int max=0;
  int answer=0;
  
  for(int i=0;i<N;i++){
    if (max<=H.at(i)) {
      max=H.at(i);
      answer++;
    }
  }
  
  cout<<answer<<endl;
}
    