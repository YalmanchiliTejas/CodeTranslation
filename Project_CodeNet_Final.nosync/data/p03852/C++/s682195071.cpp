#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
  char boin[5] = {'a', 'i', 'u', 'e', 'o'};
  char c;
  cin >> c;
  rep(i, 5){
    if(c == boin[i]){
      cout << "vowel" << endl;
      return 0;
    }
  }
  cout << "consonant" << endl;
}