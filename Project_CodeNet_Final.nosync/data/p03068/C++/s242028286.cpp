#include <iostream>
#include <string>

using namespace std;

int main()
{
  int N;
  cin >> N;
  string S;
  cin >> S;
  int K;
  cin >> K;

  for (int i = 0; i < N; i++) {
	if (S[i] != S[K - 1])
	  cout << '*';
	else
	  cout << S[i];
  }
  cout << endl;
  
  return 0;
}
