#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, tmp, count=1;
  cin >> N;
  vector<int> H(N);
  for (int i=0; i<N; i++)
    cin >> H.at(i);
  tmp = H.at(0);
  for (int i=1; i<N; i++){
    if(H.at(i) >= tmp){
      tmp = H.at(i);
      count++;
    }
  }
  cout << count << endl;
}