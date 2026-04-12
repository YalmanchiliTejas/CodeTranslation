#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n';
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll POSITIVE_INFINITY = 9223372036854775807;
const ll NEGATIVE_INFINITY = -9223372036854775807;
const ll MOD = 1000000007;
const ld PI = acos(-1.0);

template <typename T> inline T bigMod(T A,T B,T M = MOD){A %= M;T ret = 1;while(B){if(B & 1) ret = (ret * A) % M;A = (A * A) % M;B = B >> 1;}return ret;}
template <typename T> inline T invMod (T A,T M = MOD){return bigMod(A,M-2,M);}

const int N = 105;
string ar;
int k, n;
ll dp[N + 2][2][5];
ll F(int pos, int choto, int dis){
  if (dis > k){
    return 0;
  }
  if (pos >= n){
    if (dis == k){
      return 1;
    } 
    return 0;
  }
  if (dp[pos][choto][dis] != -1){
    return dp[pos][choto][dis];
  }
  ll sum = 0;
  if (choto){
    for (int i = 0; i < 10; i++){
      sum += F(pos + 1, choto, dis + (i != 0));
    }
  } else {
    int d = ar[pos] - '0';
    for (int i = 0; i <= d; i++){
      sum += F(pos + 1, i < d, dis + (i != 0));
    }
  }
  return dp[pos][choto][dis] = sum;
}

int main(){
  FASTER;
  memset(dp, -1, sizeof dp);
  cin >> ar;
  n = ar.size();
  cin >> k;
  cout << F(0, 0, 0) << "\n";
  return 0;
}