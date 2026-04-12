#include<iostream>
#include<variant>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<climits>
#include<unordered_map>
#include<set>

using namespace std;

int main() {
	long long int n;
	int x, m, st = -1, en = -1, f = 0;
	cin >> n >> x >> m;
	long long int a = x, cnt = 0, total = 0;
	unordered_map<long long int,bool> note;
	vector<long long int> sub;
	for (int i = 0; i < n; i++) {
		if (note.find(a) != note.end()) {
			if (f == 0) {
				st = i;
				f = 1;
			}
			else if (sub[0] == a) {
				en = i;
				break;
			}
			sub.push_back(a);
			total += a;
		}
		note[a] = true;
		cnt+=a;
		a = (a * a) % m;
	}
	if (en != -1) {
		n -= en;
		cnt += total * (n / (en - st));
		n = n % (en - st);
		for (int i = 0; i < n; i++) {
			cnt += sub[i];
		}
	}
	cout << cnt;
	return 0;
}