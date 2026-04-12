#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

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
int A, B, C, X, Y;
cin >> A >> B >> C >> X >> Y;

int min_p = min(X, Y);
int max_p = max(X, Y);
ll sum = 0;
if(C * 2 < A + B){
    sum += (C * 2) * min_p;
}else{
    sum += (A + B) * min_p;
}
// print(sum);

int rem = max_p - min_p;

if(X > Y && A <= (C * 2)) sum += A * rem;
else if(X < Y && B <= (C * 2)) sum += B * rem;
else sum += (C * 2) * rem;
 
print(sum);
}