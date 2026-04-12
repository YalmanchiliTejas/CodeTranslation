#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int N;

int A[26], work[26];

int main(){
  ios_base::sync_with_stdio(false); 
  cin >> N;
  memset(A, 101, sizeof(A));
  for(int i = 0; i<N; ++i){
    string s;
    cin >> s;
    memset(work, 0, sizeof(work));
    for(int j=0; j<(int)s.length(); ++j){
      ++work[s[j] - 'a'];
    }
    for(int j=0; j<26; ++j){
      A[j] = min(work[j], A[j]);
    }
  }
  string res = "";
  for(int i=0; i<26; ++i){
    for(int j=0; j<A[i]; ++j)
      cout << char(i+'a');
  }
  cout << "\n";
  return 0;
}
