#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<char> a;
	int i, j;
	char x[10] = {0};
	cin >> x;
	i = 0;
	while (x[i])
	{
		a.push_back(x[i]);
		i++;
	}
	j = 0;
	for (i = 0; i < a.size()-1; i++)
	{
		if (a[i] == 'A'&&a[i + 1] == 'C')
		{
			cout << "Yes" << endl;
			j++;
			break;
		}
	}
	if (!j)cout << "No" << endl;
	return 0;
}