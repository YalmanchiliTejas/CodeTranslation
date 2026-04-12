#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define REP(i,n) for(int i = 0; i < n; i++)
const int N = 1e5+3;
const int INF = 1e9;

int a[51][26];
int cnt[26];

int main(){

  int n; cin >> n;
  REP(i,n){
    string str; cin >> str;
    REP(j,str.size()){
      int t = str[j] - '0';
      a[i][t-49]++;
    }
  }

  string ans = "";
  char c = 'a';
  REP(j,26){
    int cnt = INF;
    REP(i,n){
      cnt = min(cnt,a[i][j]);
    }
    while( cnt-- ) ans += c;
    c++;
  }
  cout << ans << endl;

  return 0;
}
