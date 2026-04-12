#include <iostream>
#include<sstream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

void wfs(int pos, int& cnt, vector<bool> hist, const vector<vector<bool>>& table)
{
	hist[pos] = true;
	if(count(hist.begin(), hist.end(), false) == 0)
	{
		cnt++;
		return;
	}

	for(int i=1; i<table[pos].size(); i++)
	{
		if(table[pos][i] != true || hist[i] != false)
			continue;

		wfs(i, cnt, hist, table);
	}
}

int main(void)
{
	int N, M;
	cin >> N >> M;

	vector<vector<bool>> table(N, vector<bool>(N, false));
	for(int i=0; i<M; i++)
	{
		int a, b;
		cin >> a >> b;

		a--;
		b--;

		table[a][b] = true;
		table[b][a] = true;
	}

	int ret = 0;
	wfs(0, ret, vector<bool>(N, false), table);

	cout << ret << endl;

	return 0;
}
