#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9
#define PI 3.14159265359
#define MOD 1000000007
#define ALL(v) v.begin(),v.end()
#define ALLR(v) v.rbegin(),v.rend()
typedef long long ll;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
//isPrime
//modpow modinv
//getDigit
int main() {
  cout << fixed << setprecision(10);
  int h,w;
  cin >> h >> w;
  vector<string> a;
  rep(i,h){
    string s;
    cin >> s;
    bool x = true;
    rep(j,w){
      if(s.at(j)=='#')x=false;
    }
    if(!x){
      a.push_back(s);
    }
  }
  for(int j=w-1; j>=0; j--){
    bool x = true;
    rep(i,a.size()){
      if(a.at(i).at(j)=='#')x=false;
    }
    if(x){
      rep(i,a.size()){
        a.at(i).erase(a.at(i).begin()+j);
      }
    }
  }

  rep(i,a.size()){
    cout << a.at(i) << endl;
  }
}
