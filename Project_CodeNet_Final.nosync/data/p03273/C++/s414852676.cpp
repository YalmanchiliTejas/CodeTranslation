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
 
 int H, W;
 cin >> H >> W;

 vector<string>a(H);
 REP(i, H) cin >> a.at(i);


 vector<bool> h_flag(H, false), w_flag(W,false);
 REP(i, H)REP(j, W){ 
     if(a.at(i).at(j) == '#') {
         h_flag.at(i) = true;
         w_flag.at(j) = true;
    }
 }
REP(i, H){
    if(h_flag.at(i)) {
        REP(j, W){
            if(w_flag.at(j)) {
                cout << a.at(i).at(j);
            }
            if(j == W - 1) cout << endl;
    }
    }
}
 }