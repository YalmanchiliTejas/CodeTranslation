#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<bool>> isneighbor(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        isneighbor[a-1][b-1] = true;
        isneighbor[b-1][a-1] = true;
    }
    vector<int> vertex(n);
    iota(all(vertex), 0);
    int count = 0;
    do
    {
        if (vertex[0] != 0) continue;
        bool isonestroke = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (isneighbor[vertex[i]][vertex[i+1]] == false)
            {
                isonestroke = false;
                break;
            }
        }
        if (isonestroke == true) count++;
    } while(next_permutation(all(vertex)));
    cout << count << endl;
}