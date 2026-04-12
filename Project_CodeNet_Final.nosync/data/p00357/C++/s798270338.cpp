#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
#include<queue>
#include<set>
#include<map>
#include<functional>

using namespace std;
#define LL long long
#define LLBIG 1999999999999999999
#define INTBIG 1111111111
#define MOD 1000000007
#define PI pair<int,int>
#define VI vector<int>
#define VVI vector<vector<int>>

int N, dg[300003], db[300003];
int pg[300003] = {}, pb[300003] = {};
bool flg = true;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int d; cin >> d; d /= 10;
		dg[i] = db[N - 1 - i] = d;
	}
	pg[0] = dg[0]; pb[0] = db[0];
	if (!(pg[0] * pb[0]))
		flg = false;
	else {
		for (int i = 1; i < N - 1; i++) {//行き
			pg[i] = max(pg[i - 1] - 1, dg[i]);
			if (!pg[i]) {
				flg = false; break;
			}
		}
		if (flg) {
			for (int i = 1; i < N - 1; i++) {//帰り
				pb[i] = max(pb[i - 1] - 1, db[i]);
				if (!pb[i]) {
					flg = false; break;
				}
			}
		}
	}
	cout << (flg ? "yes" : "no") << endl;
	return 0;
}

