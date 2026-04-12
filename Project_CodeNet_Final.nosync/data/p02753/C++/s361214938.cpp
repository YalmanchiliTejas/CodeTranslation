//A.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
const ll mod=1e9+7;

int main(){
  string s;
  cin >> s;
  if(s[0] == 'A' &&s[1] == 'A' &&s[2] == 'A') printf("No\n");
  else if(s[0] == 'B' &&s[1] == 'B' &&s[2] == 'B') printf("No\n");
  else printf("Yes\n");
  return 0;
}
