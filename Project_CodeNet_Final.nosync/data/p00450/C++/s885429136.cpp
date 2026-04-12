#include<iostream>
#include<stack>
using namespace std;

struct stone { int color, st, en; };

int main() {
	int n;
	while (cin >> n, n) {
		stack<stone>s;
		int a;
		cin >> a;
		stone e = { a,1,1 };
		s.push(e);
		for (int i = 1;i < n;i++) {
			int b;
			cin >> b;
			if (i % 2 == 0) {
				stone t = s.top();
				if (t.color == b) {
					s.pop();
					t.en++;
					s.push(t);
				}
				else {
					s.push({ b,i + 1,i + 1 });
				}
			}

			else {
				stone t = s.top();
				if (t.color == b) {
					s.pop();
					t.en++;
					s.push(t);
				}
				else {
					s.pop();
					if (s.empty()) {
						s.push({ b, 1, i + 1 });
					}
					else {
						stone x = s.top();
						s.pop();
						s.push({ b,x.st,i + 1 });
					}
				}
			}

		}
		int c = s.size();
		int ans = 0;
		for (int i = 0;i < c;i++) {
			stone d = s.top();
			s.pop();
			if (d.color == 0)ans += (d.en - d.st + 1);
		}
		cout << ans << endl;
	}
	return 0;
}