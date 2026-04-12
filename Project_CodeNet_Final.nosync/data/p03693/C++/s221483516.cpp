#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <set>
#include <cstdlib>
#include <queue>

using namespace std;

typedef long long llint;
typedef long double ld;
#define inf 1e18

priority_queue<llint,vector<llint>,greater<llint>> que;
priority_queue<llint> q;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

llint r,g,b;

void solve(){
	cin >> r >>g >> b;
	llint a=r*100+g*10+b;
	if(a%4==0)cout << "YES" << endl;
	else cout << "NO" << endl;

}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
