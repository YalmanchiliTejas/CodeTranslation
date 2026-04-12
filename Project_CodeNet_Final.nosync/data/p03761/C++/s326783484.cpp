#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
using namespace std;
typedef long long ll;

int main()
{
  int N;
  string S[100];
  int s[100][26] = {0};
  int res[26];
  cin >> N;

  rep(i,N) {
    cin >> S[i];
  }
  rep(i,N){
    rep(j,S[i].length()){
      s[i][S[i][j]-'a']++;
    }
  }
  rep(i,26) res[i] = s[0][i];
  FOR(i,1,N-1){
    rep(j,26){
      res[j] = min(res[j], s[i][j]);
    }
  }

  rep(i,26){
    while(res[i]>0){
      char c = 'a' + i;
      cout << c;
      res[i]--;
    }
  }
  cout << endl;
}
