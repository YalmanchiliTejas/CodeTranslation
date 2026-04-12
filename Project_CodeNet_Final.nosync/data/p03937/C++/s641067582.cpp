#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define np next_permutation
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define pi acos(-1.0)
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'0'+=16;        で大文字に
//'大文字'+=32;    で小文字に
//s[i]-'0'でchar文字→int数に;
//string s = to_string(int数);
//int n = stoi(string文字列)
//cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる


int main() {
  int a,b;
  cin >>a>>b;
 
  int cnt=0;
  vector<string> p(a);
  rep(i,a){
  cin>>p[i];
    rep(j,b){
    if(p[i][j]=='#')cnt++;
    }
  }
  
  
/*  
  rep(i,a){
    rep(j,b){
      rep(k,a){
        rep(l,b){
          if(p[i][j]=='#' && p[k][l]=='#' && ((i>j && k<l)||(i<j && k>l))){
          cout << "Impossible" << endl;
          return 0;
          }
        }
      }
    }
  }
 
  cout << "Possible" << endl;
*/
  
  cout << (cnt==a+b-1?"Possible":"Impossible") << endl;
  
}
