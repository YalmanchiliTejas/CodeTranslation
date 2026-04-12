#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define INF 100100100
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
 string s;
 cin >> s;
 int a = 0, b = 0;
 rep(i,3){
   if(s.at(i) == 'B') ++b;
   if(s.at(i) == 'A') ++a;
 }
 if(a == 3 || b == 3) cout << "No" << endl;
 else cout << "Yes" << endl;
  return 0;
}
