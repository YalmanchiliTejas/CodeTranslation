#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin >> n;
  string S[50];
  for(int i = 0; i < n; i++) cin >> S[i];
  for(char c = 'a'; c <= 'z'; c++){
    int m = 100;
    for(int i = 0; i < n; i++)
      m = min(m,(int)count(begin(S[i]),end(S[i]),c));
    for(int i = 0; i < m; i++) cout << c;
  }
  cout << endl;
}