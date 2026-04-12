#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
    cin>>N;
  vector<int> h(N);
for (int i = 0; i < N; i++) {
  cin >> h.at(i);
}

  int m=0;
  int ans=0;
  for(int j=0; j<N;j++){
    if(h.at(j)>=m){
      ans++;}
    m=max(m,h.at(j));
  }
  cout <<ans<< endl;
}