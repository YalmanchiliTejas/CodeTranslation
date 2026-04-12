#include<iostream>
#include<deque>

int main(void) {
	int n;
	std::cin >> n;
	std::deque<int> deq;
	bool isEven;
	int temp;
	if (n % 2 == 0) isEven = true;
	else isEven = false;

	if (isEven) {
		for (int i = 0; i < n; i++) {
			std::cin >> temp;
			if (i % 2 == 0) deq.push_back(temp);
			else deq.push_front(temp);
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			std::cin >> temp;
			if (i % 2 == 0) deq.push_front(temp);
			else deq.push_back(temp);
		}
	}

	for (int i = 0; i < n; i++) {
		temp = deq.front();
		deq.pop_front();
		std::cout << temp;
		if (i != n - 1) std::cout << " ";
		else std::cout << std::endl;
	}
	return 0;
}
