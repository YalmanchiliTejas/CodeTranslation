#include<bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define REPvec(itr, mp) for(auto itr = mp.begin();itr != mp.end(); itr ++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
using namespace std;
typedef long long ll;
typedef vector<int >    vecint;
typedef vector<ll >    vecll;
typedef vector<string > vecstr;
////////////////////////////////////////////////
int main()
{
  int n;
  cin >> n;
  map<char, int> a;
  string s, s0;
  cin >> s;
  REP(i, s.size()){
    a[s[i]] ++;
  }
  s0 = s;
  REP(i,n - 1){
    cin >> s;
    map<char, int> b;
    REP(i,s.size()){
      b[s[i]] ++;
    }
    REP(i,s.size()){
      a[s[i]] = min(a[s[i]], b[s[i]]);
    }
    REP(i,s0.size()){
      a[s0[i]] = min(b[s0[i]], a[s0[i]]);
    }

  }
  string ans;
  REPvec(itr,a){
    // cout << itr->first << " " << itr->second << endl;
    if(itr->second > 0){
      REP(i,itr->second){
	cout << itr->first ;
      }
    }
  }
  cout << endl;
}