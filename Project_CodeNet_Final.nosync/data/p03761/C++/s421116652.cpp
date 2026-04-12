#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  vector<int> words(26);
  rep(i, s[0].length()){
    int index = s[0][i] - 'a';
    words[index]++;
  }
  for(int i = 1; i < n; ++i){
    vector<int> tmp(26);
    rep(j, s[i].length()){
      int index = s[i][j] - 'a';
      tmp[index]++;
    }
    rep(j, 26){
      words[j] = min(words[j], tmp[j]);
    }
  }
  rep(i, 26){
    char c = 'a' + i;
    rep(j, words[i]){
      cout << c;
    }
  }
  cout << endl;
}