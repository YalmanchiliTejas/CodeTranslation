#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solver
{
private:
	string str;

public:
	Solver() {
		cin >> str;
	}

	void exec() {
		for (int i = 0; i < str.size() - 1; ++i)
		{
			if(str[i] == 'A' && str[i+1] == 'C') {
				cout << "Yes" << endl;
				return;
			}
		}
		cout << "No" << endl;
	}
	
};

int main() {
	Solver ce = Solver();
	ce.exec();
}
