#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

//long long
using ll = long long;

//出力系
#define print(x) cout << x << endl
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
 
// begin() end()
#define all(x) (x).begin(),(x).end()

//for
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n, i##_len=(n); i>=0; i--)
#define FOR(i,a,b) for(int i=(a), i##_len=(b); i<i##_len; ++i)

//最大公約数 
unsigned gcd(unsigned a, unsigned b) {
  if(a < b) return gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
} 

int main(){
int X, Y, Z;
cin >> X >> Y >> Z;

X -= Z;
int cnt = 0;

while(X >= 0){
X -= Y + Z;
if(X >= 0) cnt++;
}

print(cnt);
}

