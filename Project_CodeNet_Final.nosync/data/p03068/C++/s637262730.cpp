#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
 
int main() {
  int N, K;
  cin >> N;
  string S;
  cin >> S;
  cin >> K;
  
  char t = S[K-1];
  for (int i=0; i<S.size(); ++i){
    if (S[i] != t){
      S[i] = '*';
    }
  }
  cout << S << endl;
}