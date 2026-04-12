#include <iostream>
using namespace std;

int main() {
  int N, K;
  string S;
  char SelectedChar;
  cin >> N >> S >> K;
  SelectedChar = S.at(K-1);

  for(int i = 0; i < N; i++){
    if (S.at(i) != SelectedChar) {
      S.at(i) = '*';
    }
  }
  cout << S << endl;
}