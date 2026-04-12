#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<sstream>
#include<cmath>
#include<iterator>
#include<bitset>
using namespace std;
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long ll;
int readint() { int x; cin >> x; return x; }
const int INF = 1 << 30;
const int maxn =200005;
struct Num {
	int val, id;
	Num(int val,int id):val(val),id(id){}
	bool operator<(const Num& rhs)const {
		return val < rhs.val;
	}
	Num(){}
}a[maxn];
int ans[maxn];
int main() {

	int n;
	while (cin >> n) {
		int x;
		for (int i = 0; i < n; ++i) {
			cin >> x; a[i] = Num(x, i);
		}
		sort(a, a + n);
	
		for (int i = 0; i < n; ++i) {
			ans[a[i].id] = ((n-1) / 2 >= i ? a[(n-1)/2+1].val : a[(n-1)/2].val);
		}
		_for(i, 0, n)cout << ans[i] << endl;
		cout << endl;
	}

	
	return 0;
}