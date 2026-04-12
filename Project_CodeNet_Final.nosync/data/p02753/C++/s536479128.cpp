#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  vector<char> S(3);
  int counter = 0;
  
  rep(i,3){
    cin >> S.at(i);
    if(S.at(i) == 'A')
      counter++;
  }
  
  if(counter == 1 || counter == 2)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  
  
  
}