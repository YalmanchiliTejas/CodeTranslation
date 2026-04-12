#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
  int n,k;
  string s;
  cin >> n>>s>>k;
  rep(i,s.size()){
    if(s.at(i)!=s.at(k-1)) s[i]='*';
  }
  cout<<s<<endl;
}

