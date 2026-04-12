#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define repo(i,N) for(int i = 1; i < (N); i++)
#define pb push_back
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
//#define num 1000000007
#define pi acos(-1.0)
//cout << fixed << setprecision (20);   小数点以下2０桁まで
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'大文字'+=32;    で小文字に
//string s = to_string(int数);
//int n = stoi(string文字列);
//桁数に注意 long long　にする

int main() {
  int n;
  cin >> n;
  int ans = 0;
  int taka = 0;
  
  vector<int> p(n);
  
  rep(i,n) {
  cin >> p[i];
   if(taka<=p[i])ans++;
  taka = max(taka, p[i]);
  }
  
  cout << ans << endl;
  
}
