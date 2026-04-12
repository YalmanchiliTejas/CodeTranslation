#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,m,count;
  count = 0;
  m = 0;
  cin >> N;
  vector<int> H(N);
  for(int i=0;i<N;i++){
    cin >> H.at(i);
    }
  for(int i=0;i<N;i++){
    if(m<=H.at(i)){
      count++;
    m = H.at(i);
    }
  }
  cout << count << endl;
}
