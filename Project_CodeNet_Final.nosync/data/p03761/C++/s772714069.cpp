#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> a(N, vector<int>(26));

  for (int i = 0; i < N; i++) {
    string s;
    cin>>s;
    for (int j = 0; j < s.size(); j++) {
      int k=s.at(j)-'a';
      a.at(i).at(k)++;
    }
      
  }
  for (int i = 0; i < 26; i++) {
    int mi=50;
    for (int j = 0; j < N; j++) {
      mi=min(mi,a.at(j).at(i));
    }
    while(mi--){
      char ans='a'+i;
      cout<<ans;
    }
  }
  
  
  
}