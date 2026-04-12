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
#define mod 1000000007
typedef long long ll;
using namespace std;

int main(){
  string s; cin >> s;
  if(s[0] != s[1] || s[1] != s[2] || s[2] != s[0]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}