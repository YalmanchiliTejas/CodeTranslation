#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;
#define rep(i,n) for(i = 0; i < n; i++)
#define FOR(i,m,n) for(i = m, i < n; i++)
#define repr(i,n) for(i = n; i >= 0; i--)
#define INF = 999999999
#define SORT(v,n) sort(v, v+n)
#define ALL(x) (x).begin(),(x).end()

typedef long long ll;
const int MOD = 1000000007;

  
int main(){
  int x,y,z;
  cin >> x >> y >> z;
  cout << (x - z) / (y + z) << endl;

  return 0;
}
       
