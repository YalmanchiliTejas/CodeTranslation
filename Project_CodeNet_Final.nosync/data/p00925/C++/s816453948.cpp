#include "bits//stdc++.h"
using namespace std;
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
int expression(string &exp, int &pos);
int term(string &exp, int &pos);
int factor(string &exp, int &pos);
int expression(string &exp, int &pos) {
	int ret = term(exp, pos);
	while (pos < exp.size() && exp[pos] == '+') {
		pos++;
		(ret += term(exp, pos));
	}
	return ret;
}
int term(string &exp, int &pos) {
	int ret = factor(exp, pos);
	while (pos < exp.size() && exp[pos] == '*') {
		pos++;
		(ret *= term(exp, pos));
	}
	return ret;
}
int factor(string &exp, int &pos) {
	int num = exp[pos] - '0';
	pos++;
	return num;
}
int main() {
	string exp;
	cin >> exp;
	int bobs_ans;
	cin >> bobs_ans;
	int pos = 0;
	int true_ans = expression(exp, pos);
	int false_ans = exp[0] - '0';
	for (int i = 1; i < exp.size(); i += 2) {
		if (exp[i] == '+') {
			false_ans += exp[i + 1] - '0';
		}
		else {
			false_ans *= exp[i + 1] - '0';
		}
	}
	if (bobs_ans == true_ans && bobs_ans == false_ans) {
		cout << "U" << endl;
	}
	else if (bobs_ans == true_ans) {
		cout << "M" << endl;
	}
	else if (bobs_ans == false_ans) {
		cout << "L" << endl;
	}
	else {
		cout << "I" << endl;
	}
}
