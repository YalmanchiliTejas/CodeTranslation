#include <iostream>
#include <cstring>
using namespace std;

int H, W, C, M, Nw, Nc, Nm, Win, Wout, Cin, Cout, Mio, s, t, res;
int cap[310][310];
bool used[310];
enum { source = 300, sink, nwin, nwout, ncin, ncout, nmio };

bool dfs(int v)
{
    used[v] = true;
    for(int i = 0; i < 310; ++i)
        if(cap[v][i] > 0 && !used[i])
            if(i == sink || dfs(i)) {
                --cap[v][i]; ++cap[i][v]; return true;
            }
    return false;
}

int main()
{
    while(cin >> H >> W >> C >> M && H >= 0)
    {
        memset(cap, 0, sizeof(cap));
        cin >> cap[nwin][nwout] >> cap[ncin][ncout] >> cap[nmio][sink];
    	Mio = (Cout = (Cin = (Wout = (Win = H) + W) + W) + C) + C;

        for(int i = 0; i < H; ++i)
            cap[source][i] = cap[i][nwin] = 1;
        for(int i = 0; i < W; ++i) {
            cin >> s;
            for(int j = 0; j < s; ++j) { cin >> t; cap[t-1][Win+i] = 1; }
            cap[Win+i][Wout+i] = cap[Wout+i][ncin] = 1;
        }
        for(int i = 0; i < C; ++i) {
            cin >> s;
            for(int j = 0; j < s; ++j) { cin >> t; cap[Wout+t-1][Cin+i] = 1; }
            cap[nwout][Cin+i] = cap[Cin+i][Cout+i] = cap[Cout+i][nmio] = 1;
        }
        for(int i = 0; i < M; ++i) {
            cin >> s;
            for(int j = 0; j < s; ++j) { cin >> t; cap[Cout+t-1][Mio+i] = 1; }
            cap[ncout][Mio+i] = cap[Mio+i][sink] = 1;
        }

        res = 0;
        do fill_n(used, 310, false); while(dfs(source) && ++res);
        cout << res << endl;
    }
}