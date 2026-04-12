#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
//#define num 1000000007
#define pi acos(-1.0)
//cout << fixed << setprecision (20);   小数点以下2０桁まで
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'0'+=16;        で大文字に
//'大文字'+=32;    で小文字に
//s[i]-'0'でchar文字→int数に;
//string s = to_string(int数);
//int n = stoi(string文字列)
//実行時間制約2秒では２×10^8回くらいまで計算できる


int main() {
  int n,m;
  cin >> n >> m;
  vector<pair<int,int>> p(m);
  
  rep(i,m) {
  cin >> p[i].fi >> p[i].se;
  }
  
  vector<int> q={};
  rep(i,n-1) {
  q.pb(i+2);
  }
  
  int ans = 0;
  
  do{
    bool x = false;
    rep(j,m) {
      if((p[j].fi==1 && p[j].se==q[0]) || 
          (p[j].fi==q[0] && p[j].se==1)) {
      x = true;
      }
    }
    
    int aru = 0;
    repo(i,n-1) {
      rep(j,m) {
        if((p[j].fi==q[i-1] && p[j].se==q[i]) || 
          (p[j].fi==q[i] && p[j].se==q[i-1])) {
         aru++;
        }
      }
    } 
   if(x && aru==n-2) ans++;
    
  }while (np(all(q)));
  
  cout << ans << endl;  
  
}