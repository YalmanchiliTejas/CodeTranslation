#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());
#define vecmin(A) *min_element(A.begin(),A.end());
#define vecmax(A) *max_element(A.begin(),A.end());
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> vv(n,vector<int>(26));
  rep(i,n){
    string s;
    cin >> s;
    for(char c : s){
      int x = c - 'a';
      vv[i][x] ++;
    }
  }
  for(int i=0;i<26;i++){
    int tmp = 1000000000;
    for(int j=0;j<n;j++){
      tmp = min(tmp,vv[j][i]);
    }
    rep(j,tmp) cout << (char)(i+'a');
  }
  cout << endl;
}