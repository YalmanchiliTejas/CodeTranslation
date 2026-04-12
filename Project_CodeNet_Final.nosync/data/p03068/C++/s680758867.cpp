#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 10000000;
typedef pair<int,int> P;
typedef long long ll;
/*
*/

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int K;
  cin >> K;
  char c = S[K-1];
  string ans;
  
  for(int i = 0;i<N;i++){
    if(S[i] != c) ans.push_back('*');
    else ans.push_back(S[i]);
  }
  cout << ans << endl;
}