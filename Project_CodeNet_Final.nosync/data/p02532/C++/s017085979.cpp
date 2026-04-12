#include<iostream>
#include<stack>
#include<queue>

int main(){
	std::string command;
	std::stack<char> stack[101]; 
	std::queue<char> p_queue;
	while(std::cin >> command, command != "quit"){
		if(command == "pop"){
			int p;
			std::cin >> p;
			p_queue.push(stack[p].top());
			stack[p].pop();
		}else if(command == "push"){
			int p;
			char c;
			std::cin >> p >> c;
			stack[p].push(c);
		}else if(command == "move"){
			int p1, p2;
			std::cin >> p1 >> p2;
			stack[p2].push(stack[p1].top());
			stack[p1].pop();
		}
	}
	while(!p_queue.empty()){
		std::cout << p_queue.front() << std::endl;
		p_queue.pop();
	}
	return 0;
}