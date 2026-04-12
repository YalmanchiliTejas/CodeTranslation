#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<math.h>
#include<assert.h>
#include<string>
#include<cstdlib>
#include<cctype>
// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll INF = 1LL << 40;
const double INFD = 1e100;
const ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
// ----------------------------------------------------------------------------

int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int ans=mod;
  for(int c=0; c<=200000; c+=2){
    int sum=0;
    if(X>c/2){
      sum += (X-c/2)*A;
    }
    if(Y>c/2){
      sum += (Y-c/2)*B;
    }
    sum += c*C;
    chmin(ans,sum);
  }
  cout << ans << endl;
  return 0;
}
