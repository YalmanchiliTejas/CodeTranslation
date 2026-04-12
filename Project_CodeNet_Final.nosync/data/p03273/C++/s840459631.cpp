#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define SZ(x) ((int)(x).size())
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const double pi=acos(-1);




int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> masu(H, vector<char>(W));
  rep (i, H) {
    rep (j, W) {
    cin >> masu.at(i).at(j);
    }
  }

  vector<bool> black1(H, false);
  rep (i, H) {
    rep (j, W) {
      if (masu.at(i).at(j)=='#') black1.at(i) = true;
    } 
  }
  
  vector<bool> black2(W, false);
  rep (i, W) {
    rep (j, H) {
      if (masu.at(j).at(i)=='#') black2.at(i) = true;
    }
  }
  
  int count = 0;
  rep (i, W) {
  if (black2.at(i)) count++;
  }  
  
  int memo = 0;
  
  rep (i, H) {
    rep (j, W) {
      if (black1.at(i) && black2.at(j)) {
      cout << masu.at(i).at(j);
      memo++;
        if (memo==count) {
        cout << endl;
        memo=0;
        }
      }
    } 
  }
  
  
  
}
