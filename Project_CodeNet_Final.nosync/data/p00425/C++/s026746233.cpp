#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Dice {
public:
	int p[7] = { 0,1,4,5,2,3,6 };
	void North() {
		swap(p[3], p[1]);
		swap(p[1], p[4]);
		swap(p[4], p[6]);
	}
	void East() {
		swap(p[5], p[1]);
		swap(p[1], p[2]);
		swap(p[2], p[6]);
	}
	void West() {
		swap(p[1], p[5]);
		swap(p[5], p[6]); 
		swap(p[6], p[2]);
	}
	void South() {
		swap(p[1], p[3]);
		swap(p[3], p[6]);
		swap(p[6], p[4]);
	}
	void Right() {
		swap(p[2], p[4]);
		swap(p[4], p[5]);
		swap(p[5], p[3]);
	}
	void Left() {
		swap(p[2], p[3]);
		swap(p[3], p[5]);
		swap(p[5], p[4]);
	}
};
int main()
{
	while (1) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		string s[10000];
		Dice D;
		int count = 1;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			if (s[i][0] == 'N')
				D.North();
			if (s[i][0] == 'E')
				D.East(); 
			if (s[i][0] == 'W')
				D.West();
			if (s[i][0] == 'S')
				D.South();
			if (s[i][0] == 'R')
				D.Right();
			if (s[i][0] == 'L')
				D.Left(); 
			count += D.p[1];
			}
			cout << count << endl;
	}
	return 0;
}