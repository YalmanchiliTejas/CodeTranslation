#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define INF 1e9
#define all(v) v.begin(), v.end()
typedef long long ll;

ll f1(string s){
  ll n = s.size();
  if(n <= 0) return 0;
  return (s[0]-'0') + (n-1)*9;
}

ll f2(string s){
  ll n = s.size();
  if(n <= 1) return 0;
  ll p1 = ((n-1)*(n-2)*9*9)/2;
  ll p2 = (s[0]-'1') * (n-1) * 9;
  string t = s;
  do{
    t.erase(t.begin());
  }while(t[0] == '0');
  ll p3 = f1(t);
  
  return p1+p2+p3;
}

ll f3(string s){
  ll n = s.size();
  if(n <= 2) return 0;
  ll p1 = ((n-1)*(n-2)*(n-3)*9*9*9)/6;
  ll p2 = (s[0]-'1') * ((n-1)*(n-2)*9*9)/2;
  string t = s;
  do{
    t.erase(t.begin());
  }while(t[0] == '0');
  ll p3 = f2(t);

  return p1+p2+p3;
}

int main(){
  string st;
  int k;
  cin >> st >> k;
  
  ll ans;
  if(k==1) ans = f1(st);
  if(k==2) ans = f2(st);
  if(k==3) ans = f3(st);

  cout << ans << endl;

  return 0;
}
