#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int INF = 100000000;
const long INF64 = 1000000000000000ll;
const int MOD = 1000000007;
int main(){
  int a,b,c;
  std::cin >> a>>b>>c;
  c=c+a*100+b*10;
  if(c%4==0)std::cout << "YES" << std::endl;
  else std::cout << "NO" << std::endl;
}