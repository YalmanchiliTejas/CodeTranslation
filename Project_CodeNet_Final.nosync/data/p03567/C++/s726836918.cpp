#include <bits/stdc++.h>
typedef long long LL;
#define SORT(c) sort((c).begin(),(c).end())
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
 
using namespace std;
int main(void)
{
  string s;
  cin >> s;
  cout << (s.find("AC")==string::npos?"No":"Yes") << endl;
  return 0;
}