#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
typedef unsigned long long ull;
typedef long long ll;
#define MAX 105
#define __TRUE "YES"
#define __FALSE "NO"
#define cout(x) cout << (x) << endl
#define reps(i,s,n) for(i=s;i<n;i++)
#define rep(i,n) for(i=0;i<n;i++)
using namespace std;

int main() {
  char c;
  cin >> c;
  if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o') cout("vowel");
  else cout("consonant");

  return 0;
}