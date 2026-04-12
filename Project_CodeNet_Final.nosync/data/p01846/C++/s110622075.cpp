#include "bits/stdc++.h"
using namespace std;
#define mod 1000000007
#define all(c) begin(c),end(c)
template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
using ll = long long;
using vi = vector<int>; using vs = vector<string>;
int dd[] = { 0, 1, 0, -1, 0 }; //→↓←↑

vs V;
void split(string S, char v)
{
	string s = "";
	for (int i = 0; i <= S.size(); i++)
	{
		if (i == S.size() || S[i] == v)
		{
			V.emplace_back(s);
			s = "";
		}
		else
		{
			s += S[i];
		}
	}
}
void solve()
{
	string S;
	bool B[10][10];
	while (cin >> S, S != "#")
	{
		memset(B, 0, sizeof(B));
		V.clear();
		split(S, '/');

		int H = V.size();
		int W;
		for (int i = 0; i < V.size(); i++)
		{
			int x = 0;
			for (int j = 0; j < V[i].size(); j++)
			{
				if (isdigit(V[i][j]))
				{
					x += V[i][j] - '0';
				}
				else
				{
					B[i][x] = true;
					x++;
				}
			}
			W = x;
		}
		//cout << H << " " << W << endl;

		int a, b, c, d;
		cin >> a >> b >> c >> d;
		B[--a][--b] = false;
		B[--c][--d] = true;

		for (int i = 0; i < H; i++)
		{
			int cnt = 0;
			for (int j = 0; j <= W; j++)
			{
				if (j == W)
				{
					if (cnt > 0)
					{
						cout << cnt;
					}
					if (i < H - 1)
					{
						cout << '/';
					}
				}
				else if (B[i][j])
				{
					if (cnt > 0)
					{
						cout << cnt;
					}
					cnt = 0;
					cout << 'b';
				}
				else
				{
					cnt++;
				}
			}
		}
		cout << endl;
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
