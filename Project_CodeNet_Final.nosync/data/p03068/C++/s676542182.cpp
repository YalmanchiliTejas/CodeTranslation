#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,k,a,b;
string s,t;

int main() {
  cin >> n >> s >> k;
  rep(i,n){
    if(s[i]!=s[k-1])
    s[i]='*';   
  }
  cout << s << endl;
}