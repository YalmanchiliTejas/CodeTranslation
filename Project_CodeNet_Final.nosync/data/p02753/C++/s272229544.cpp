#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;

int main(){
  string s;
  cin >> s;
  if(s[0]!=s[1]||s[0]!=s[2]||s[1]!=s[2]){ cout << "Yes" << endl; }else{ cout << "No" << endl;}
  return 0;
}
