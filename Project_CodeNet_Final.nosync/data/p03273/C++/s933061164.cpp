#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<string> In_list(N);
	vector<vector<bool>> Out_list(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++)
	{
		cin >> In_list.at(i);
	}

	for (int i = 0; i < N; i++)
	{
		bool flag = true;
		for (int j = 0; j < M; j++)
		{
			if (In_list.at(i).at(j) == '.' && flag != false)
			{
				flag = true;
			}
			else
			{
				flag = false;
			}
		}
		if (flag == true)
		{
			for (int j = 0; j < M; j++)
			{
				Out_list.at(i).at(j) = true;
			}
		}
	}

	for (int j = 0; j < M; j++)
	{
		bool flag = true;
		for (int i = 0; i < N; i++)
		{
			if (In_list.at(i).at(j) == '.' && flag != false)
			{
				flag = true;
			}
			else
			{
				flag = false;
			}
		}
		if (flag == true)
		{
			for (int i = 0; i < N; i++)
			{
				Out_list.at(i).at(j) = true;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		bool flag = false;
		for (int j = 0; j < M; j++)
		{
			if (Out_list.at(i).at(j) == false)
			{
				cout << In_list.at(i).at(j);
				flag = true;
			}
		}
		if (flag == true)
		{
			cout << endl;
		}
	}
}
