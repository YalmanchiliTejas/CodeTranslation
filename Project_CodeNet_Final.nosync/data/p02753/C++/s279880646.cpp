#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T&a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T&a,T b){if(a>b){a=b;return 1;}return 0;}
const long long MOD = 1000000007;
typedef long long ll;

int n,k;
string s,t;
int a[100005];

int main() {
  cin >> s;
  int cnt=0;
  rep(i,3)if(s[i]=='A') cnt++;
  cout << (cnt==3 || cnt==0 ? "No" : "Yes") << endl;
}