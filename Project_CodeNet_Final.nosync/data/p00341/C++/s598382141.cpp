#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int i[12];
	for (int a = 0; a < 12; a++)
	{
		cin >> i[a];
	}
	sort(i, i + 12);
	if (i[0] == i[2] && i[0] == i[1] && i[0] == i[3] &&
		i[4] == i[6] && i[4] == i[5] && i[7] == i[4] &&
		i[8] == i[9] && i[8] == i[10] && i[8] == i[11])
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}