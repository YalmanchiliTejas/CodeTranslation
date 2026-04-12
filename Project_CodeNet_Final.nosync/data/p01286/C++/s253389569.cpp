#include <iostream>
#include <cstring>
using namespace std;

int H, W, C, M, s, t, res, cap[310][310];
bool used[310];
enum { source = 300, sink, nwin, nwout, ncin, ncout, nmio };

bool dfs(int v)
{
    used[v] = true;
    for(int i = 0; i < 310; ++i)
        if(cap[v][i] > 0 && (i == sink || (!used[i] && dfs(i)))) {
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

        for(int i = 0; i < H; ++i)
            cap[source][i] = cap[i][nwin] = 1;
        for(int i = 0; i < W; ++i) {
        	cin >> s;
            for(int j = 0; j < s; ++j) { cin >> t; cap[t-1][50+i] = 1; }
            cap[50+i][100+i] = cap[100+i][ncin] = 1;
        }
        for(int i = 0; i < C; ++i) {
        	cin >> s;
            for(int j = 0; j < s; ++j) { cin >> t; cap[100+t-1][150+i] = 1; }
            cap[nwout][150+i] = cap[150+i][200+i] = cap[200+i][nmio] = 1;
        }
        for(int i = 0; i < M; ++i) {
        	cin >> s;
            for(int j = 0; j < s; ++j) { cin >> t; cap[200+t-1][250+i] = 1; }
            cap[ncout][250+i] = cap[250+i][sink] = 1;
        }

        res = 0;
        do fill_n(used, 310, false); while(dfs(source) && ++res);
        cout << res << endl;
    }
}