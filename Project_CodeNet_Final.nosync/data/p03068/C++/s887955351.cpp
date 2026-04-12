#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int N, K;
  string S;
  cin >> N >> S >> K;
  char r = S[K-1];
  for(char c:S)
  {
    if(c !=r)
      cout << '*';
    else
      cout << c;
  }
  cout << endl;
  return 0;
}
