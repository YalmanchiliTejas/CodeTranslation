#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

#define fi first
#define se second

int main() {
	int n;
	bool flag = false;

	while(cin >> n, n) {
		priority_queue<pair<pair<int,int>,string> > q;
		if(flag) {
			cout << endl;
		}
		for(int i = 0; i < n; i++) {
			pair<pair<int,int>, string> tmp;
			int win, lose, draw;
			string team;
			cin >> team >> win >> lose >> draw;
			
			tmp.fi.fi = win * 3 + draw;
			tmp.fi.se = n - i;
			tmp.se = team;

			q.push(tmp);
		}

		while(!q.empty()) {
			pair<pair<int,int>, string> tmp;
			tmp = q.top(); q.pop();
			cout << tmp.se << "," << tmp.fi.fi << endl;
		}
		flag = true;
	}

	return 0;
}