#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  string S;
  cin >> S;
  for(int i = 0; i < 4; i++) {
    if(S[i] == 'A' && S[i + 1] == 'C') {
      cout << "Yes" << endl;
      return (0);
    }
  }
  cout << "No" << endl;
}