#include <iostream>
using namespace std;
#include <string>
#define N 1000
#define S 1000

int main()
{
	string code;
	int sidx;				// the index of stacks
	char color;
	char stack[S][N];
	int s = 0;
	int sn[S];				// the number of items of the stack
	int from, to;
	
	cin >> s;
	
	while (1) {
		cin >> code;
		if (code == "push") {
			cin >> sidx >> color;
			stack[sidx - 1][sn[sidx - 1]] = color;
			sn[sidx - 1]++;
		} else if (code == "pop") {
			cin >> sidx;
			cout << stack[sidx - 1][sn[sidx - 1] - 1] << "\n";
			sn[sidx - 1]--;
		} else if (code == "move") {
			cin >> from >> to;
			stack[to - 1][sn[to - 1]] = stack[from - 1][sn[from - 1] - 1];
			sn[from - 1]--;
			sn[to - 1]++;
		} else if (code == "quit") {
			break;
		}
	}
	return 0;
}