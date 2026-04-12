#include<iostream>
#include<string>

using namespace std;

int main(int argc, char const *argv[]) {
  int N,K;
  string S;
  cin >> N >> S >> K;
  char a = S[K-1];
  for (int i = 0; i < S.size(); i++) {
    cout << (S[i]==a ? a:'*');
  }
  cout << endl;
}
