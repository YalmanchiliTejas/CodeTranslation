#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define INF 100

int N;
int H[16], W[16];
string C[4];

string color = "RGB";
int mask[16][16][16][16];
int Cmask[3];

void printState(int state)
{
	rep(y, 0, 4)
	{
		rep(x, 0, 4)
		{
			int m = (state >> (15 - (y * 4 + x))) & 1;
			cout << m;
		}
		cout << endl;
	}
}

int solve()
{
	queue<int> que;

	que.push(0);
	
	int dist[1 << 16];
	rep(i, 0, 1 << 16) dist[i] = INF;
	dist[0] = 0;

	while (!que.empty())
	{
		int state = que.front(); que.pop();

		if (state == (1 << 16) - 1) return dist[state];

		rep(i, 0, N) rep(j, 0, 3)
		{
			rep(ssy, -(H[i] - 1), 4) rep(ssx, -(W[i] - 1), 4)
			{
				int ttx = ssx + W[i] - 1;
				int tty = ssy + H[i] - 1;

				int sx = max(ssx, 0);
				int sy = max(ssy, 0);
				int tx = min(ttx, 3);
				int ty = min(tty, 3);

				//cout << "--------------" << endl;
				//printState(state);

				int m = (~mask[sx][sy][tx][ty]) & ((1 << 16) - 1);
				int nstate = state & m;
				int mm = Cmask[j] & mask[sx][sy][tx][ty];
				nstate = nstate | mm;

				if (dist[nstate] == INF)
				{
					dist[nstate] = dist[state] + 1;
					que.push(nstate);
				}

				//cout << endl;
				//printState(nstate);
			}
		}
	}

	return -1;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	while (cin >> N)
	{
		rep(i, 0, N) cin >> H[i] >> W[i];
		rep(i, 0, 4) cin >> C[i];

		rep(sx, 0, 4) rep(tx, sx, 4) rep(sy, 0, 4) rep(ty, sy, 4)
		{
			int m = 0;

			rep(y, 0, 4) rep(x, 0, 4)
			{
				if ((sx <= x && x <= tx) && (sy <= y && y <= ty))
					m = (m << 1) + 1;
				else
					m = (m << 1);
			}

			mask[sx][sy][tx][ty] = m;
		}

		rep(i, 0, 3)
		{
			int m = 0;
			rep(y, 0, 4) rep(x, 0, 4)
			{
				if (C[y][x] == color[i])
					m = (m << 1) + 1;
				else
					m = m << 1;
			}
			Cmask[i] = m;
		}

		cout << solve() << endl;
	}
}