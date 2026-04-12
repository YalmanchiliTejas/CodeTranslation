#include <iostream>
#include <queue>
#include <stack>

int n;

std::queue<int> f;
std::stack<int> s, in;

int main() {

	std::cin >> n;

	int a;

	for (int i = 0; i < n; ++i) {
		std::cin >> a;
		in.emplace(a);
	}

	if (in.size() == 1) {
		std::cout << in.top() << std::endl;
		return 0;
	}

	while (!in.empty()) {

		f.emplace(in.top());
		in.pop();

		if (!in.empty()) {

			s.emplace(in.top());
			in.pop();
		}
	}

	while (!f.empty()) {
		std::cout << f.front() << ' ';
		f.pop();
	}

	while (s.size() > 1) {
		std::cout << s.top() << ' ';
		s.pop();
	}

	std::cout << s.top() << std::endl;

	//system("pause");

	return 0;
}