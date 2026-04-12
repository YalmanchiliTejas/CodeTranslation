#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
  int N;
  cin >> N;
  string S[N];
  for(int i=0;i<N;i++) cin >> S[i];

  int cnt[26];
  fill(cnt,cnt+26,100);
  for(int i=0;i<N;i++){
    int cnttmp[26];
    fill(cnttmp,cnttmp+26,0);
    for(int j=0;j<S[i].size();j++){
      int ind = S[i][j] - 'a';
      cnttmp[ind]++;
    }
    for(int j=0;j<26;j++){
      cnt[j] = min(cnt[j] , cnttmp[j]);
    }
  }

  for(int i=0;i<26;i++){
    for(int j=0;j<cnt[i];j++){
      cout << (char)('a' + i);
    }
  }
  cout << endl;
  return 0;
}