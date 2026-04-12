#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
  cin.tie(0); ios_base::sync_with_stdio(0);
  string s;
  cin >> s;
  for(int i=0;i<2;i++) {
    if (s[i]!=s[i+1]) {
      cout << "Yes" <<endl;
      return 0;
    }
  }
  cout << "No" <<endl;
}
