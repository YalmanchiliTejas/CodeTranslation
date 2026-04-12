#include <bits/stdc++.h>
using namespace std; 

vector<long long> a, p;

long long f(int N, long long X) {
	if (N == 0) {
		if (X <= 0) {
            return 0;
        }
        else {
            return 1;
        }
	}
	else if (X <= 1 + a.at(N - 1)) {
		return f(N - 1, X - 1);
	}
	else if (X == 2 + a.at(N - 1)) {
		return (p.at(N - 1) + 1);
	}
	else {
		return (p.at(N - 1) + f(N - 1, X - (2 + a.at(N - 1))) + 1);
	}
}

int main() {
	int N;
	long long X;
	cin >> N >> X;
	
	
	a = {1};
	p = {1};
	for (int i = 1; i <= N; i++) {
		a.push_back(a.at(i - 1) * 2 + 3);
		p.push_back(p.at(i - 1) * 2 + 1);
	}
	cout << f(N, X) << endl;
}