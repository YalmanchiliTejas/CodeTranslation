#include <bits/stdc++.h>
typedef long long lint;

#define PI acos(-1)
#define INF64 1LL << 60
#define INF32 1 << 29
#define all(a) (a).begin(), (a).end()

using namespace std;

void execute()
{
	int N;
	string input;
	bool tmp;
	int ans_num = -1;
	cin >> N;
	cin >> input;
	input = input[N - 1] + input;
	vector<vector<bool>> ans(4, vector<bool>(N + 2));
	ans[0][0] = ans[0][1] = ans[1][0] = ans[2][1] = true;
	ans[1][1] = ans[2][0] = ans[3][0] = ans[3][1] = false;

	for (int i = 2; i < N + 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ans[j][i] = ans[j][i - 1] ^ ans[j][i - 2] ^ (input[i - 2] == 'o');
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (ans[i][0] == ans[i][N] && ans[i][1] == ans[i][N + 1])
			ans_num = i;
	}

	if (ans_num == -1)
	{
		cout << ans_num << endl;
		return;
	}
	for (int i = 2; i < N + 2; i++)
	{
		cout << (ans[ans_num][i] ? "S" : "W");
	}
	cout << endl;
	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	execute();

	int stop;
	cin >> stop;

	return 0;
}