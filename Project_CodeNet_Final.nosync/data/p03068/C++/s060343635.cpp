#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k;
	cin >> k;
	char j = s.at(k-1);
	for (int i = 0; i < n; i++)
	{
		if (s.at(i) != j)
		{
			s.at(i) = '*';
		}
	}
	cout << s << endl;


}