#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<cassert>
#include<queue>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;

int main() {
	int r, g, b;
	cin >> r >> g >> b;
	if ((10*g+b)%4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
