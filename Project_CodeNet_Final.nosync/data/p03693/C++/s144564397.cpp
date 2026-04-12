#include <bits/stdc++.h>
#include <math.h>
#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;
const int mINF = -1001001001;


int main() {
int r,g,b;
cin >> r >> g >> b;
int ans = g*10+b;
if(ans%4==0) {
  cout << "YES" <<endl;
} else {
  cout << "NO" << endl;
}
return 0;
}
