#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  
  int N,K;
  string S;
  cin >> N >> S >> K;

  char ch = S.at(K-1);
  for(int i = 0;i < N;i++) {
    if(S.at(i) == ch) cout << ch;
    else cout << '*';
  }

  cout << endl;
}

