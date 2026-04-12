#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<string> S(N);
  for(int i=0; i<N; i++) cin >> S.at(i);
  vector<int> comm(26);
  for(int i=0; i<26; i++) comm.at(i)=50;
  for(int i=0; i<N; i++){
    vector<int> cnt(26);
    int L = S.at(i).size();
    for(int j=0; j<L; j++){
      cnt.at(S.at(i).at(j)-97)++;
    }
    for(int j=0; j<26; j++){
      comm.at(j)=min(comm.at(j), cnt.at(j));
    }
  }
  
  for(int i=0; i<26; i++){
    for(int j=0; j<comm.at(i); j++) cout << char(i+97);
  }
  cout << endl;
}