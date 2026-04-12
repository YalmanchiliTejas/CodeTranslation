#include <bits/stdc++.h>
using namespace std;
int main(){
  int R,G,B;
  cin >> R >> G >> B;
  int n = 10*G + B;
  string answer = "NO";
  if(n%4 == 0) answer = "YES";
  cout << answer << endl;
}