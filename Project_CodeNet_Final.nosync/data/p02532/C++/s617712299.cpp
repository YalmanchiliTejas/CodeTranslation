#include <iostream>
#include <stack>
#include <vector>

auto main() -> int {
	int n_stacks;
	std::cin >> n_stacks;

	std::vector<std::stack<char>> stacks(n_stacks);
	for (;;) {
		std::string order;
		std::cin >> order;
		if (order == "quit") {
			break;
		}

		if (order == "push") {
			int dst;
			char block;
			std::cin >> dst;
			std::cin >> block;
			stacks[dst-1].push(block);
		}

		if (order == "pop") {
			int src;
			char block;
			std::cin >> src;
			block = stacks[src-1].top();
			std::cout << block << std::endl;
			stacks[src-1].pop();
		}

		if (order == "move") {
			int src;
			int dst;
			char block;
			std::cin >> src;
			std::cin >> dst;
			block = stacks[src-1].top();
			stacks[dst-1].push(block);
			stacks[src-1].pop();
		}
	}
	return 0;
}