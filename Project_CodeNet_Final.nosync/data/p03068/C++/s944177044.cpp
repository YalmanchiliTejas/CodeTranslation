#include <bits/stdc++.h>
using namespace std;

int main() {
 int N,K;
 cin >> N;
 string S;
 cin >> S;
 cin >> K;
 char s=S[K-1];
 int i;
 for (i=0;i<N;++i) {
  if (S[i] != s) {
   S[i] = '*';
  }
 }
 cout << S <<endl;
 
}