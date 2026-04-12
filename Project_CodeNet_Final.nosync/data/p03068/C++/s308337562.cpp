#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K = 0;
  string S;

  cin >> N >> S >> K;

  char str1 = S[K-1];

  int count = 0;
  string outS;

  for (int i = 0; i < N; i++) {
	if(S[i] == str1) {
		outS = outS + str1;
	} else {
		outS = outS + '*';
	}
  }

  cout << outS << endl;

}