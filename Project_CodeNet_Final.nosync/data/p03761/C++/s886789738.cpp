#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define mod 1000000007
typedef long long ll;
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> S(n);
  rep(i,n) cin >> S[i];
  vector<int> cnt(26);

  for(int i=0;i<n;i++){
    vector<int> cnt_(26);
    rep(j,26) cnt_[j]=0;
    for(int j=0;j<(int)S[i].size();j++){
      if(i==0){
        cnt[(char)S[i][j]-'a']++;
      }
      else{
        cnt_[(char)S[i][j]-'a']++;
      }
    }
    if(i!=0){
      for(int j=0;j<26;j++){
        cnt[j] = min(cnt[j],cnt_[j]);
      }
    }
  }
  rep(i,26){
    rep(j,cnt[i]){
      cout << (char)('a'+i);
    }
  }
  cout << endl;
  return 0;
}
