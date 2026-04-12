#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = unsigned long long;

const int MAXN = 500;
const ll MAXP = 64;

ll mat[MAXN][MAXN];
bool cond_lig[MAXN];
bool cond_col[MAXN];
ll val_lig[MAXN];
ll val_col[MAXN];
int N;

ll or_line(int line)
{
	ll ret(0);
	for (int i(0); i < N; ++i)
		ret |= mat[line][i];
	return ret;
}

ll and_line(int line)
{
	ll ret(mat[line][0]);
	for (int i(0); i < N; ++i)
		ret &= mat[line][i];
	return ret;
}

ll or_col(int col)
{
	ll ret(0);
	for (int i(0); i < N; ++i)
		ret |= mat[i][col];
	return ret;
}

ll and_col(int col)
{
	ll ret(mat[0][col]);
	for (int i(0); i < N; ++i)
		ret &= mat[i][col];
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i(0); i < N; ++i)
		cin >> cond_lig[i];
	for (int i(0); i < N; ++i)
		cin >> cond_col[i];
	for (int i(0); i < N; ++i)
		cin >> val_lig[i];
	for (int i(0); i < N; ++i)
		cin >> val_col[i];

	for (ll p(0); p < MAXP; ++p)
	{
		ll bit = (1ULL<<p);
		int lig0f(0), lig0a(0), lig1f(0), lig1a(0);
		int col0f(0), col0a(0), col1f(0), col1a(0);
		for (int lig(0); lig < N; ++lig)
		{
			if (cond_lig[lig])
			{
				if (bit&val_lig[lig])
					lig1a++;
				else
					lig0f++;
			}
			else
			{
				if (bit&val_lig[lig])
					lig1f++;
				else
					lig0a++;
			}
		}
		for (int col(0); col < N; ++col)
		{
			if (cond_col[col])
			{
				if (bit&val_col[col])
					col1a++;
				else
					col0f++;
			}
			else
			{
				if (bit&val_col[col])
					col1f++;
				else
					col0a++;
			}
		}
		if ((col1f and lig0f) or (col0f and lig1f))
		{
			cout << -1 << endl;
			return 0;
		}
		for (int lig(0); lig < N; ++lig)
			if (!cond_lig[lig] and (bit&val_lig[lig]))
				for (int col(0); col < N; ++col)
					mat[lig][col] |= bit;
		for (int col(0); col < N; ++col)
			if (!cond_col[col] and (bit&val_col[col]))
				for (int lig(0); lig < N; ++lig)
					mat[lig][col] |= bit;
		if ((lig1a or lig1f) and (col1a or col1f))
		{
			for (int lig(0); lig < N; ++lig)
				for (int col(0); col < N; ++col)
					if ((bit&val_lig[lig]) and (bit&val_col[col]))
						mat[lig][col] |= bit;
		}	
		else if (lig1a)
		{
			bool fst(true);
			vector<int> col_can;
			for (int col(0); col < N; ++col)
				if (!cond_col[col] and !(bit&val_col[col]))
					col_can.push_back(col);
			if (SZ(col_can) == 0)
			{
				cout << -1 << endl;
				return 0;
			}
			if (SZ(col_can)==1)
			{
				for (int lig(0); lig < N; ++lig)
					if (cond_lig[lig] and (bit&val_lig[lig]))
						mat[lig][col_can[0]] |= bit;
			}
			else
			{
				for (int lig(0); lig < N; ++lig)
				{
					if (cond_lig[lig] and (bit&val_lig[lig]))
					{
						if (fst)
						{
							mat[lig][col_can[0]] |= bit;
							fst = false;
						}
						else
							mat[lig][col_can[1]] |= bit;
					}
				}
			}
		}
		else if (col1a)
		{
	
			bool fst(true);
			vector<int> lig_can;
			for (int lig(0); lig< N; ++lig)
				if (!cond_lig[lig] and !(bit&val_lig[lig]))
					lig_can.push_back(lig);
			if (SZ(lig_can) == 0)
			{
				cout << -1  << endl;
				return 0;
			}
			if (SZ(lig_can)==1)
			{
				for (int col(0); col< N; ++col)
					if (cond_col[col] and (bit&val_col[col]))
						mat[lig_can[0]][col] |= bit;
			}
			else
			{
				for (int col(0); col< N; ++col)
				{
					if (cond_col[col] and (bit&val_col[col]))
					{
						if (fst)
						{
							mat[lig_can[0]][col] |= bit;
							fst = false;
						}
						else
							mat[lig_can[1]][col] |= bit;
					}
				}
			}
		}
	}
	
	for (int lig(0); lig < N; ++lig)
	{
		if (cond_lig[lig])
		{
			if (or_line(lig) != val_lig[lig])
			{
				cout << -1 << endl;
				return 0;
			}
		}
		else
		{
			if (and_line(lig) != val_lig[lig])
			{
				cout << -1 << endl;
				return 0;
			}
		}
	}
	for (int col(0); col < N; ++col)
	{
		if (cond_col[col])
		{
			if (or_col(col) != val_col[col])
			{
				cout << -1 << endl;
				return 0;
			}
		}
		else
		{
			if (and_col(col) != val_col[col])
			{
				cout << -1 << endl;
				return 0;
			}
		}
	}
	for (int lig(0); lig < N; ++lig)
		for (int col(0); col < N; ++col)
			cout << mat[lig][col] << " \n"[col==N-1];
}
