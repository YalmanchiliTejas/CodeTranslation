#include<iostream>
#include<string>
#include<vector>

using namespace std;

template<typename T>
istream& operator >> (istream& is, vector<T>& vec) {
	for (T& x : vec) is >> x;
	return is;
}

int main() {
	int db[50];
	for (int i = 0; i < 50; i++)
	{
		db[i] = 50;
	}
	int n;
	cin >> n;
	vector<string> s(n);
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		int buf[50] = { 0 };

		for (int j = 0; j < s[i].length(); j++)
		{
			buf[s[i][j] - 'a']++;
		}
		for (int j = 0; j < 50; j++)
		{
			if (buf[j] < db[j])
				db[j] = buf[j];
		}
	}
	for (int i = 0; i < 50; i++)
	{
		if (db[i] > 0)
		{
			for (int j = 0; j < db[i]; j++)
			{
				cout << char(i + 'a');
			}
		}
	}
	cout << endl;
}