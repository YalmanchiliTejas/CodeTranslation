#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  int n; cin >> n;
  vector<int> tot(26,100);
  string s;
  rep(i,n){
    cin >> s;
    vector<int> tmp(26,0);
    rep(j,s.size()) tmp[s[j]-'a']++;

    rep(k,26) tot[k] =  min(tot[k],tmp[k]);
  }

  rep(i,26){
    rep(j,tot[i]) {
      char c = 'a' + i;
      cout << c;
    }
  }
  cout << endl;




  
  
  // cout << fixed << setprecision(10);
  
  return 0;
}
