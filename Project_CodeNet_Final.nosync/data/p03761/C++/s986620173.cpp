#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<climits>
#define MOD 1000000007
typedef long long ll;
using namespace std;

const int MAX = 55;

// num[i][j] S_iに含まれるj番目のアルファベットの個数
int num[MAX][26];

// mini[i] 全てのSに含まれるi番目のアルファベットの個数
int mini[26];
int main(){
  int n; cin >> n;
  for(int i=0;i<n;i++){
    string s; cin >> s;
    for(int j=0;j<s.size();j++){
      num[i][s[j]-'a']++;
    }
  }

  for(int i=0;i<26;i++) mini[i] = num[0][i];

  for(int i=0;i<26;i++){
    for(int j=0;j<n;j++){
      mini[i] = min(mini[i], num[j][i]);
    }
  }

  for(int i=0;i<26;i++){
    for(int j=0;j<mini[i];j++) cout << (char)('a'+i);
  }
  cout << endl;
  return 0;
}