#include<iostream>
#include<iomanip>
#include<algorithm>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<map>
#include<numeric>
#include<set>
#include<sstream>
#include<string>
#include<utility>
#include<vector>

#define rep(i, a, n)  for(int i=a; i<n; ++i)
#define per(i, a, n)  for(int i=n-1; i>=a; --i)
#define fill0(n)  setfill('0') << right << setw(n)
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define INF 1000000007
using namespace std;
typedef long long ll;

int main(){
  int N;  cin >> N;
  vector<int> H(N);
  rep(i, 0, N){
    cin >> H[i];
  }
  int ans = 0;
  rep(i, 0, N){
    bool able = true;
    rep(j, 0, i){
      if(H[i]<H[j]) able = false;
    }
    if(able)  ans++;
  }
  cout << ans << endl;
  return 0;
}