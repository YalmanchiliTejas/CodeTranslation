#include <iostream>
#include <string>
using namespace std;

int main()
{
  string S;
  int N, K;
  cin >> N >> S >> K;
  
  char c = S[K-1];
  
  for (int i = 0; i < S.size(); ++i)
    if (S[i] != c)
      S[i] = '*';
  
  cout << S;
}
