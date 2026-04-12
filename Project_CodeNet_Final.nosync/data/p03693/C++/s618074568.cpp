#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1000000007;

int main() {
  int r,g,b;
  cin>>r>>g>>b;
  int rgb=r*100+g*10+b;
  cout<<(rgb%4==0 ? "YES":"NO")<<endl;
}