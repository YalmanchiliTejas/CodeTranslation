#include <bits/stdc++.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<string> S(N);
	for (size_t i = 0; i < N; i++)
	{
		cin >> S.at(i);
		sort(S.at(i).begin(), S.at(i).end());
	}
	vector<vector<int>> chara(26, vector<int>(N));
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < S.at(i).size(); j++)
		{
			chara.at(int(S.at(i).at(j) - 'a')).at(i)++;
		}
	}
	for (size_t i = 0; i < 26; i++)
	{
		sort(chara.at(i).begin(), chara.at(i).end());
	}
	for (size_t i = 0; i < 26; i++)
	{
		for (size_t j = 0; j < chara.at(i).at(0); j++)
		{
			cout << char('a' + i);
		}
	}
	
}