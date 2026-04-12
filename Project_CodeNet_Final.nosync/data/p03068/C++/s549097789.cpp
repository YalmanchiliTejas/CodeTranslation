#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;

int main() {
  int N,K;
  string S;
  cin >> N>> S>>K;
  char s;
  s = S.at(K-1);
  for(int i = 0; i < N; i++) {
    if(S.at(i) == s) {
      cout << s;
    }
    else{
      cout << '*';
    }
  }
  cout << endl;
}