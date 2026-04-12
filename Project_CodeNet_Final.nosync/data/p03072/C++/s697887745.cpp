#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> H(N);
  for (int i=0; i<N; i++){
    cin>>H.at(i);
  }
  int Hmax=0;
  int count=0;
  for(int i=0; i<N; i++){
    if (Hmax<=H.at(i)){
      Hmax=H.at(i);
      count++;
    }
  }
  cout<<count<<endl;
}