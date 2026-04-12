#include <bits/stdc++.h>
using namespace std;

int main(){

  int N, s[27], t[27];
  char ans;
  cin >> N;
  string S, T;
  for(int i=0; i<N; i++){
    for(int j=0; j<27; j++) s[j] = 0;
    cin >> S;
    for(int j=0; j<S.size(); j++) s[S[j]-'a']++;
    if(i==0) for(int j=0; j<27; j++) t[j] = s[j];
    for(int j=0; j<27; j++) t[j] = min(t[j], s[j]);
  }

  for(int i=0; i<27; i++){
    ans = i + 'a';
    for(int j=0; j<t[i]; j++) cout << ans << flush;
  }

  return 0;
}
