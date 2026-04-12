#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
// ascending order
#define vsort(v) sort(v.begin(), v.end())
// descending order
#define vsort_r(v) sort(v.begin(), v.end(), greater<int>())
#define vunique(v) unique(v.begin(), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;

#define MAX_V 1000000

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	ll res = 0;
	int tmpC = C * 2;
	if(A + B <= tmpC) {
		res = A * X + B * Y;
		cout << res << endl;
	} else {
		if(X < Y) {
			res += (tmpC * X);
			Y -= X;
			if(tmpC < B) res += tmpC * Y;
			else res += B * Y;
			cout << res << endl;
		} else {
			res += (tmpC * Y);
			X -= Y;
			if(tmpC < A) res += tmpC * X;
			else res += A * X;
			cout << res << endl;
		}
	}

}
