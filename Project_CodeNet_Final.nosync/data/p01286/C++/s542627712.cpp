#include <iostream>
#include <cstring>
using namespace std;

int H, W, C, M, Nw, Nc, Nm, s, t, res;
int Win, Wout, Cin, Cout, Mio, V;
int cap[310][310];
bool used[310];
enum { source = 300, sink, nwin, nwout, ncin, ncout, nmio };

bool dfs(int v, int t)
{
	if(v == t) return true;
	used[v] = true;
	for(int i = 0; i < 310; ++i)
		if(cap[v][i] > 0 && !used[i])
			if(dfs(i, t)) {
				--cap[v][i]; ++cap[i][v]; return true;
			}
	return false;
}

int main()
{
	while(cin >> H >> W >> C >> M >> Nw >> Nc >> Nm && H >= 0)
	{
		Win  = H;
		Wout = Win  + W;
		Cin  = Wout + W;
		Cout = Cin  + C;
		Mio  = Cout + C;

		memset(cap, 0, sizeof(cap));
		for(int i = 0; i < H; ++i) {
			cap[source][i] = 1;
			cap[i][nwin] = 1;
		}
		for(int i = 0; i < W; ++i) {
			cin >> s;
			for(int j = 0; j < s; ++j) { cin >> t; cap[t-1][Win+i] = 1; }
			cap[Win+i][Wout+i] = 1;
			cap[Wout+i][ncin] = 1;
		}
		for(int i = 0; i < C; ++i) {
			cin >> s;
			for(int j = 0; j < s; ++j) { cin >> t; cap[Wout+t-1][Cin+i] = 1; }
			cap[nwout][Cin+i] = 1;
			cap[Cin+i][Cout+i] = 1;
			cap[Cout+i][nmio] = 1;
		}
		for(int i = 0; i < M; ++i) {
			cin >> s;
			for(int j = 0; j < s; ++j) { cin >> t; cap[Cout+t-1][Mio+i] = 1; }
			cap[ncout][Mio+i] = 1;
			cap[Mio+i][sink] = 1;
		}
		cap[nwin][nwout] = Nw;
		cap[ncin][ncout] = Nc;
		cap[nmio][sink]  = Nm;

		res = 0;
		while(true)
		{
			fill_n(used, 310, false);
			if(!dfs(source, sink)) break;
			++res;
		}
		cout << res << endl;
	}
}