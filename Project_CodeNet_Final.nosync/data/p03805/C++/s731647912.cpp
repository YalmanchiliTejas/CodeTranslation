#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <tuple>

#define INF 100000000

using namespace std;
bool NODE_FLAG[10] = {false}, SIDE_FLAG[30] = {false};
int n, m, ans_count = 0;

pair<int, int> SIDE[30];

//すべてのNODEを通ったかチェック
bool reach_check()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (NODE_FLAG[i] == true)
        {
            cnt++;
        }
        //cout << NODE_FLAG[i] << " ";
    }
    //cout << "\n\n";
    if (cnt == n)
    {
        return true;
    }
    return false;
}

void BFS(int E_NODE)
{
    for (int i = 0; i < m; i++)
    {
        //順方向から見
        if (SIDE[i].first == E_NODE && NODE_FLAG[SIDE[i].second] == false && SIDE_FLAG[i] == false)
        {
            //cout << SIDE[i].first << " " << SIDE[i].second << endl;
            SIDE_FLAG[i] = true;
            NODE_FLAG[SIDE[i].second] = true;
            if (!reach_check()) //未到達のNODEがあればBFSへ
            {
                BFS(SIDE[i].second);
            }
            else
            {
                ans_count++;
            }
            NODE_FLAG[SIDE[i].second] = false;
            SIDE_FLAG[i] = false;
        }

        //逆方向から
        else if (SIDE[i].second == E_NODE && NODE_FLAG[SIDE[i].first] == false && SIDE_FLAG[i] == false)
        {
            //cout << SIDE[i].first << " " << SIDE[i].second << endl;
            SIDE_FLAG[i] = true;
            NODE_FLAG[SIDE[i].first] = true;
            if (!reach_check())
            {
                BFS(SIDE[i].first);
            }
            else
            {
                ans_count++;
            }
            NODE_FLAG[SIDE[i].first] = false;
            SIDE_FLAG[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> SIDE[i].first >> SIDE[i].second;
    }
    //cout << "\n";
    NODE_FLAG[1] = true;
    //cout << SIDE[i].first << " " << SIDE[i].second << endl;
    BFS(1);
    cout << ans_count << endl;
    return 0;
}