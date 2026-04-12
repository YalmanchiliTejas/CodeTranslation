#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
typedef long long ll;


int main(){
  int x;
  cin >> x;
  if(x == 7 || 5 == x || 3 == x){
    cout << "YES" <<endl;
  }else{
    cout << "NO" << endl;
  }
  
  return 0;
}
