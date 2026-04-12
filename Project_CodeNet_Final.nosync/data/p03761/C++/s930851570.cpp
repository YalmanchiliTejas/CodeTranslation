#include <iostream>
#include<sstream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<vector<int>> table(26, vector<int>(n, 0));
	for(int i=0; i<n; i++)
	{
		string S;
		cin >> S;

		for(auto it=S.begin(); it!=S.end(); it++)
			table[*it-'a'][i]++;
	}

	vector<int> cnt(26, 0);
	for(int i=0; i<26; i++)
		cnt[i] = *min_element(table[i].begin(), table[i].end());

	for(int i=0; i<26; i++)
	{
		char ch = 'a' + i;
		cout << string(cnt[i], ch);
	}
	cout << endl;

	return 0;
}
