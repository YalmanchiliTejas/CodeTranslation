#include <bits/stdc++.h>

#ifdef LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif

using namespace std;

enum { M = 1, L = 2 };
char output[] = {'I', 'M', 'L', 'U'};
int priority[128];

int parse(int l, int r, const string &expression, int p = 2) {
	for(int i = r - 1; i >= l; --i) {
		if(priority[expression[i]] == p) {
			switch(expression[i]) {
			case '+':
				return parse(l, i, expression, p) + parse(i + 1, r, expression, p);
			case '*':
				return parse(l, i, expression, p) * parse(i + 1, r, expression, p);
			default:
				assert(false);
			}
		}
	}

	return p > 1 ? parse(l, r, expression, p - 1) : stoi(expression.substr(l, r - l));
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int Bobs_answer;
	string expression;
	cin >> expression >> Bobs_answer;

	int ans = 0;

	priority['+'] = priority['*'] = 2;
	if(parse(0, expression.size(), expression) == Bobs_answer) ans |= L;

	priority['*'] = 1;
	if(parse(0, expression.size(), expression) == Bobs_answer) ans |= M;

	cout << output[ans] << endl;

	return EXIT_SUCCESS;
}