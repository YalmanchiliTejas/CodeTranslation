
#include <bits/stdc++.h>
using namespace std;

vector<int> num;
int k;
string s;
int DP[103][5][2];

int call(int pos, int cnt, int f)
{
	if (cnt > k)
		return 0;

	if (pos == num.size())
	{
		if (cnt == k)
			return 1;
		return 0;
	}

	if (DP[pos][cnt][f] != -1)
		return DP[pos][cnt][f];
	int res = 0;

	int LMT;

	if (f == 0)
	{

		LMT = num[pos];
	}
	else
	{

		LMT = 9;
	}

	for (int dgt = 0; dgt <= LMT; dgt++)
	{
		int nf = f;
		int ncnt = cnt;
		if (f == 0 && dgt < LMT)
			nf = 1;
		if (dgt != 0)
			ncnt++;
		if (ncnt <= k)
			res += call(pos + 1, ncnt, nf);
	}

	return DP[pos][cnt][f] = res;
}

int solve(string b)
{
	num.clear();
	for (int i = 0; i < s.size(); i++)
	{
		num.push_back((s[i] - '0'));
	}
	//reverse(num.begin(), num.end());
	//for (int i : num)
	//	cout << i << " ";

	memset(DP, -1, sizeof(DP));
	int res = call(0, 0, 0);
	return res;
}

int main()
{

	cin >> s >> k;
	int res = solve(s);
	cout << res << endl;

	return 0;
}
