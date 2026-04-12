#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<vector<char>> vec(n);
	vector<char> ans;
	string str;
	char c;
	int p, p2;
	while (1)
	{
		cin >> str;
		if (str == "quit")
			break;
		if (str == "pop")
		{
			cin >> p;
			//cout << vec[vec.size() - 1] << endl;
			ans.push_back(vec[p - 1][vec[p - 1].size() - 1]);
			vec[p - 1].pop_back();
		}
		if (str == "push")
		{
			cin >> p >> c;
			vec[p - 1].push_back(c);
		}
		if (str == "move")
		{
			cin >> p >> p2;
			vec[p2 - 1].push_back(vec[p - 1][vec[p - 1].size() - 1]);
			vec[p - 1].pop_back();
		}
	}
	for (char i : ans)
		cout << i << endl;
	return 0;
}