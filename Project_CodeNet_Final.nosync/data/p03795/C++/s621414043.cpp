#include <bits/stdc++.h>
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define sort_1(v) sort(v.begin(),v.end())
#define sort_2(v) sort(v.begin(),v.end(),greater<ll>())
typedef long long ll;
typedef long double la;
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans = 0;
  int count=15;
  for(int i=0;i<n;i++){
    ans += 800;
  }
  ans -= 200*(n/15);
  cout << ans << endl;
}