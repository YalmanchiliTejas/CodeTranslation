#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(30);
  for(int i=0;i<N;i++)cin >> H[i];
  int cnt=1; int M=H[0];
  for(int i=1;i<N;i++){
    if(H[i]>=M){cnt++; M=H[i];}
  }
  cout << cnt << endl;
}