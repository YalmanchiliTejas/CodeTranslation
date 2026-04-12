#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> e(12);
	bool disable = false;
	for (int i = 0; i < 12; i++)
		cin >> e[i];

	int def = e[0];
	int fndcnt = 0;
	int i = 1;
	while (1) {
		if (def == e[i]) {
			fndcnt++;
			e.erase(e.begin() + i);
			i--;
		}
		if (fndcnt == 3) {
			e.erase(e.begin());
			if (e.empty())
				break;
			else
				def = e[0];
			i = 0;
			fndcnt = 0;
		}
		else if (fndcnt > 3 || i == e.size()-1) {
			disable = true;
			break;
		}
		i++;
	}
	if (disable)
		cout << "no" << endl;
	else
		cout << "yes" << endl;
	return 0;
}