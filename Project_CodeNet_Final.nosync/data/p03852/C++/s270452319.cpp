#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  char c;
  cin >> c;
  if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
    cout << "vowel" << endl;
  }else{
    cout << "consonant" << endl;
  }
}
