#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int N_ab= 26;
  vector<int> freq_common(N_ab,INT_MAX);
  for(int i=0; i<n; i++){
    string str;
    cin >> str;

    vector<int> freq(N_ab,0);
    for(int j=0; j<str.size(); j++){
      int c_id= str.at(j)-'a';
      freq.at(c_id)++;
    }
    for(int j=0; j<N_ab; j++){
      if( freq_common.at(j) > freq.at(j) ){
        freq_common.at(j)= freq.at(j);
      }
    }
  }

  for(int j=0; j<N_ab; j++){
    for(int k=0; k<freq_common.at(j); k++){
      char c= 'a'+j;
      cout << c;
    }
  }
  cout << endl;
}