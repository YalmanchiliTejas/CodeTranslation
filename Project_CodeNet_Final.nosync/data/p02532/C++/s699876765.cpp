#include <vector>
#include <iostream>
#include <string>
const int MAX_N = 100;
using namespace std;

int main(){
	int n, p, q;
	string command, c;
	vector<string> stack[MAX_N];

	cin >> n;
	while(1){
		cin >> command;
		if(command == "quit")
			break;
		if(command == "push"){
			cin >> p >> c;
			stack[p - 1].push_back(c);
		}else{
			if(command == "pop"){
				cin >> p;
				cout << stack[p - 1][stack[p - 1].size() - 1] << "\n";
				stack[p - 1].pop_back();
			}else{
				cin >> p >> q;
				c = stack[p - 1][stack[p - 1].size() - 1];
				stack[p - 1].pop_back();
				stack[q - 1].push_back(c);
			}
		}
	}
	cout << flush;

	return 0;
}