#include <bits/stdc++.h>
using namespace std;
 
#define int long long
using pii = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1 << 29;
const int N =  1e5 + 10;
 
struct IOsetup{
  IOsetup(){
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   cout << fixed << setprecision(8);
  }
}IO;

int32_t main(){
 string s;
 cin >> s;
 for (int i = 0; i + 1 < (int)s.length(); i++){
  if (s[i] != s[i + 1]){
    cout << "Yes" << endl;
    return 0;
  }
 }
 cout << "No" << endl;
}

