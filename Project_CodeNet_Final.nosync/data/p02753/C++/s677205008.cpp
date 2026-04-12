#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
using namespace std;
typedef long long ll;

int main(){
  string s;
  cin >> s;
  
  if (s[0]==s[1] && s[0]==s[2]) dunk("No");
  else dunk("Yes");
  
}