#include <iostream>
#include <string>

using namespace std;

int N;
string S;
int K;

int main()
{
  cin >> N >> S >> K;
  char mask = S[K-1];
  for(int i = 0; i < N; ++i) {
    if(S[i] != mask)
      S[i] = '*';
  }
    cout << S << endl;
  return 0;
}