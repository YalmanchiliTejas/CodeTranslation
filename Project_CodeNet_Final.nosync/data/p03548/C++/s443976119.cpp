#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
#include<stack>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	if (x % (y + z) >= z) cout << x / (y + z) << endl;
	else cout << x / (y + z) - 1 << endl;
}