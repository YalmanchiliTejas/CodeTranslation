#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

void yes(){
  cout << "Yes" << endl;
  exit(0);
}

void no(){
  cout << "No" << endl;
  exit(0);
}
int main(){
  string s; cin >> s;
  ll n = SZ(s);
  REP(i,n-1){
    if(s[i] == 'A' && s[i+1] == 'C') yes();
   }
  no(); 
}