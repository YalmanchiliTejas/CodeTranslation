#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<string> S(n);
  vector<int> cnt(26, 50);
  for(int i = 0; i < n; i++){
    cin >> S[i];
    for(int j = 0; j < 26; j++){
      char tmp = 'a' + j;
      int res = 0;
      for(auto x: S[i]){
	if(x == tmp){
	  res++;
	}
      }
      cnt[j] = min(cnt[j], res);
    }
  }
  for(int i = 0; i < 26; i++){
    char buf = 'a' + i;
    for(int j = 0; j < cnt[i]; j++){
      cout << buf ;
    }
  }
  cout << endl;
}
