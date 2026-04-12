#include <vector>
#include <iostream>
using namespace std;
int m, n; string s; vector<int> r;
int main() {
	while(~scanf("%d%d", &m, &n)) {
		if(m == 0 && n == 0) break; int pos = 0; r.clear();
		for(int i = 1; i <= m; i++) r.push_back(i);
		for(int i = 1; i <= n; i++) {
			cin >> s;
			if(i % 15 == 0) {
				if(s != "FizzBuzz" && r.size() != 1) r.erase(r.begin() + pos);
				else pos++;
			}
			else if(i % 3 == 0) {
				if(s != "Fizz" && r.size() != 1) r.erase(r.begin() + pos);
				else pos++;
			}
			else if(i % 5 == 0) {
				if(s != "Buzz" && r.size() != 1) r.erase(r.begin() + pos);
				else pos++;
			}
			else {
				if(s != to_string(i) && r.size() != 1) r.erase(r.begin() + pos);
				else pos++;
			}
			pos %= r.size();
		}
		for(int i = 0; i < r.size(); i++) {
			if(i) printf(" ");
			printf("%d", r[i]);
		}
		printf("\n");
	}
	return 0;
}