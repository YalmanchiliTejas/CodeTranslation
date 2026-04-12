#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	string operate;
	int NumOfMt;
	cin >> NumOfMt;
	deque<string> pop_char,char_stack[NumOfMt];
	while(1){
		cin >> operate;
		if(operate == "quit") break;
		else if(operate == "push"){
			string c;
			int num;
			cin >> num >> c;
			char_stack[num - 1].push_front(c);
		}
		else if(operate == "move"){
			int num1,num2;
			cin >> num1 >> num2;
			char_stack[num2 - 1].push_front(char_stack[num1 - 1].at(0));
			char_stack[num1 - 1].pop_front();

		}
		else if(operate == "pop"){
			int num;
			cin >> num;
			pop_char.push_back(char_stack[num - 1].at(0));
			char_stack[num - 1].pop_front();
		}
	}
	for(int i  =0 ;i < pop_char.size();i++){
		cout << pop_char[i] << endl;
	}
	return 0;
}