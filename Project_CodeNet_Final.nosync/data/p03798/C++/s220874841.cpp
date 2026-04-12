#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;

int n; string s;

char add(string st, int ind)
{
  if(st[ind]=='S'){
    if(s[ind]=='o') return st[ind-1];
    else return (st[ind-1]=='S' ? 'W' : 'S');
  }else{
    if(s[ind]=='x') return st[ind-1];
    else return (st[ind-1]=='S' ? 'W' : 'S');
  }
}

bool chk1(string st)
{
  if(st[n-1]=='S'){
    if(s[n-1]=='o') return (st[n-2]==st[0]);
    else return (st[n-2]!=st[0]);
  }else{
    if(s[n-1]=='x') return (st[n-2]==st[0]);
    else return (st[n-2]!=st[0]);
  }
}

bool chk2(string st)
{
  if(st[0]=='S'){
    if(s[0]=='o') return (st[n-1]==st[1]);
    else return (st[n-1]!=st[1]);
  }else{
    if(s[0]=='x') return (st[n-1]==st[1]);
    else return (st[n-1]!=st[1]);
  }
}
      

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n >> s;
  string ans = "-1";
  REP(k,4){
    string tmp = "";
    if(k & 1) tmp.push_back('S');
    else tmp.push_back('W');
    if(k & (1<<1)) tmp.push_back('S');
    else tmp.push_back('W');
    
    FOR(i,1,n-1){
      tmp.push_back(add(tmp, i));
    }
    
    if(chk1(tmp) && chk2(tmp)){
      ans = tmp;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
