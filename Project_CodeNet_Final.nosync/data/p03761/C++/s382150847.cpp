#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
ll D = 1000000007;

int main(){
  int n;
  cin >> n;
  string S[n];

  int cnt[n][26];
  for(int i=0;i<n;i++){
    for(int j=0;j<26;j++){
      cnt[i][j] = 0;
    }
  }

  for(int i=0;i<n;i++){
    cin >> S[i];
  }

  for(int i=0;i<n;i++){
    int l = S[i].size();
    for(int j=0;j<l;j++){
      int check = S[i][j] - 'a';
      cnt[i][check]++;
    }
  }

  int common[26];
  for(int j=0;j<26;j++) common[j] = 100;

  for(int j=0;j<26;j++){
    for(int i=0;i<n;i++){
      common[j] = min(common[j], cnt[i][j]);
    }
  }

  for(int j=0;j<26;j++){
    char ch = 'a' + j;
    for(int k=0;k<common[j];k++){
      cout << ch;
    }
  }
  cout << endl;


  return 0;
}
