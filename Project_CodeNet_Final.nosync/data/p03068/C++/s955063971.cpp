/**
  @date Time-stamp: <2019-04-21 22:25:06 tagashira>
  @file a.cpp
  @brief https://atcoder.jp/contests/tenka1-2019-beginner/tasks/tenka1_2019_b
**/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int N,K;
  string S;
  cin >> N >> S >> K;

  char c =S[K-1];
  for(int i=0 ; i < N ; i++){
    if(S[i] != c){
      S[i] = '*';
    }
  }

  cout << S << "\n";

  return 0;
}
