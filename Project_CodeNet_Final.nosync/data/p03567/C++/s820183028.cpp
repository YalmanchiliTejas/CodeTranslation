#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

double n,k,h,w,va,vb,l;
string s;

int main() {
  cin >> s;
  bool ok=false;
  rep(i,s.size()){
    if(s[i]=='A' && s[i+1]=='C') ok=true;
  }
  cout << (ok ? "Yes" : "No") << endl;
}