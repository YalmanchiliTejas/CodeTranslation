#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<char>* blocks = new vector<char>[n];
	string order;
	for (cin >> order; order != "quit"; cin >> order) {
		if (order == "push") {
			int num;
			char color;
			cin >> num >> color;
			blocks[num - 1].push_back(color);
		}
		else if (order == "pop") {
			int num;
			cin >> num;
			cout << blocks[num - 1].back() << endl;
			blocks[num - 1].pop_back();
		}
		else {
			int num1, num2;
			cin >> num1 >> num2;
			char tmp = blocks[num1 - 1].back();
			blocks[num1 - 1].pop_back();
			blocks[num2 - 1].push_back(tmp);
		}
	}
	return 0;
}