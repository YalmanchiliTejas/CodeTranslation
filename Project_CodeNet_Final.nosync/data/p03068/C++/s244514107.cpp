#include<iostream>
using namespace std;
int main () {
  int N;
  cin >> N;
  char s[11];
  for (int i = 0; i < N; i ++) cin >> s[i];
  int K;
  cin >> K;
  K --;
  for (int i = 0; i < N; i ++) {
    if (s[i] == s[K]) cout << s[i];
    else cout << '*';
  }
  cout << endl;
}
