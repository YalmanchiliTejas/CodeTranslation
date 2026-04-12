#include<iostream>
#include<algorithm>
#include<complex>
#include<vector>
#include<queue>
#define LL long long
LL N;
LL add;
std::priority_queue<LL> q;
int main() {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		LL tmp;
		std::cin >> tmp;
		q.push(tmp);
	}
	while (true) {
		LL a = q.top();
		q.pop();
		if (a + add < N) {
			break;
		}
		a += add;
		LL tmp = (a  - N)/ N + 1;
		a -= tmp * N;
		add += tmp;
		a -= add;
		q.push(a);
	}
	std::cout << add << std::endl;
	return 0;
}
