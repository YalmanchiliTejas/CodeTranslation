#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,m,n;
  n=0;
  m=0;
  cin >> N;
  vector<int>H(N);
  for(int i=0;i<N;i++){
    cin >> H.at(i);
    if(H.at(i)>=m){
      n++;
      m=H.at(i);
    }
  }
    cout << n << endl;
}