#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<string> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  
  vector<int> alpha(26,51);
  for(int i=0; i<N; i++){
    vector<int> sx(26);
    string s = vec.at(i);
    for(int j=0; j<s.size(); j++){
      int z = s.at(j) - 'a';
      sx.at(z)++;
    }
    for(int k=0; k<26; k++){
        alpha.at(k) = min(alpha.at(k),sx.at(k));
    }
  }  
  
  for(int i=0; i<26; i++){
    for(int j=1; j<=alpha.at(i); j++){
      char x = 'a' + i;
      cout << x;
    }
  }
  cout << endl;
  
}