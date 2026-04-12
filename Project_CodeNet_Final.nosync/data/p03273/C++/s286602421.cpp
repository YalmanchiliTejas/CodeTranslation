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

// 最小公倍数
unsigned lcm(unsigned a, unsigned b){
    return a / gcd(a, b) * b; 
}

int main(){
int H, W;
cin >> H >> W;
char A[H][W];
REP(y, H)REP(x, W){
    cin >> A[y][x];
}

vector<bool> h_flag(H, false), w_flag(W, false);
REP(y, H)REP(x, W){
    if(A[y][x] == '#'){
        h_flag[y] = true;
        w_flag[x] = true;
    }
}

REP(y, H){
    if(h_flag[y]){
        REP(x, W){
            if(w_flag[x]) cout << A[y][x];
            if(x == W - 1) cout << endl;
        }
    }
}
}

