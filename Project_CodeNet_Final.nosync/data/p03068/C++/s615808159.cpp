#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<char> S;
  for(int i = 0;i < s.size();i++){
    S.push_back(s.at(i));
  }
  int k;
  cin >> k;
  char ans = S[k-1];
  for(int i = 0;i < s.size();i++){
    if(S[i] != ans){
      S[i] = '*';
    }
  }
  for(int i = 0;i < s.size();i++){
    cout << S[i];
  }
}
