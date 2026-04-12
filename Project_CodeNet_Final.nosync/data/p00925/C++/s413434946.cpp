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
  int n;
  cin >> n;
  int answerl=s[0]-'0';
  REP(i,s.size()/2)
    if(s[i*2+1]=='+') answerl+=(s[i*2+2]-'0');
    else answerl*=(s[i*2+2]-'0');
  int answerm=0;
  vector<int> adds;
  adds.push_back(s[0]-'0');
  REP(i,s.size()/2)
    if(s[i*2+1]=='+') adds.push_back(s[i*2+2]-'0');
    else adds[adds.size()-1]*=(s[i*2+2]-'0');
  REP(i,adds.size()) answerm+=adds[i];
  string ans="IMLU";
  int ansnum=0;
  if(n==answerm) ansnum+=1;
  if(n==answerl) ansnum+=2;
  cout << ans[ansnum] << endl;
  return 0;
}