#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int K;
  cin >> K;
  for (int i=0; i<N; i++) {
    if (S[K-1] != S[i]) {
      S[i] = '*';
    }
  }
  cout << S << endl;
}
