#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> map(N, vector<bool>(N, false));
    for (int i = 0; i < M; i++)
    {
        int p, q;
        cin >> p >> q;
        p--, q--;
        map[p][q] = true, map[q][p] = true;
    }

    vector<int> list;
    for (int i = 1; i < N; i++)
        list.push_back(i);

    int ans = 0;
    do
    {
        auto tmp = list;
        tmp.push_back(0);
        bool x = true;
        for (int i = 0; i < N - 1; i++)
            if (!map[tmp[i]][tmp[i + 1]])
                x = false;

        if(x)
            ans++;
    } while (next_permutation(list.begin(), list.end()));
    cout << ans;
}