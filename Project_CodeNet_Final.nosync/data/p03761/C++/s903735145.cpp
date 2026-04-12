#include<bits/stdc++.h>
#define INF 10000000
using namespace std;
int main(){
  int n;
  cin >> n;
  string str[51];
  int table[60][30]={};
  for(int i=0; i<n; i++){
    cin >> str[i];
    for(int j=0; j<str[i].size(); j++){
      table[i][str[i][j]-'a']++;
    }
  }
  vector<char> ans;
  for(int i=0; i<30; i++){
    int Min = INF;
    for(int j=0; j<n; j++){
      Min = min(table[j][i],Min);
      //cout << Min << endl;
    }
    for(int j=0; j<Min; j++){
      ans.push_back(i+'a');
    }
  }
  for(int i=0; i<ans.size(); i++){
    cout << ans[i];
  }
  cout << endl;
  /*
  for(int i=0; i<n; i++){
    for(int j=0; j<26; j++){
      cout << table[i][j] << " ";
    }
    cout << endl;
    }*/
  return 0;
}
