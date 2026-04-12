#include <bits/stdc++.h>
using namespace std;

int n, m;
bool mr[150], mk[150];
string s[150];
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
//  freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
  cin >> n >> m;
  for(int i = 0; i < n; ++i) cin >> s[i];
  for(int i = 0; i < n; ++i){
    int a = 0;
    for(int j = 0; j < m; ++j){
      a |= (s[i][j] == '.' ? 1:(1<<1));
    }
    if(a == 1) mr[i] = true;
  }
  for(int i = 0; i < m; ++i){
    int a = 0;
    for(int j = 0; j < n; ++j){
      a |= (s[j][i] == '.' ? 1:(1<<1));
    }
    if(a == 1) mk[i] = true;
  }
  for(int i = 0; i < n; ++i){
    if(mr[i]) continue;
    for(int j = 0; j < m; ++j){
      if(!mk[j]) cout << s[i][j];
    }
    cout << '\n';
  }
  return 0;
}
