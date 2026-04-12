#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    
    vector<vector<int>> ab(M, vector<int>(2));
    vector<vector<int>> ba(M, vector<int>(2));
    for (int i=0; i<M; i++)
    {
        int x, y;
        cin >> x >> y;
        ab[i][0] = x;
        ab[i][1] = y;
        ba[i][0] = y;
        ba[i][1] = x;
    }

    vector<int> order(N-1);
    for (int i=2; i<=N; i++) order[i-2]=i;
    
    int ans=0;
    do
    {
        vector<int> tmp_order(order);
        tmp_order.insert(tmp_order.begin(), 1);

        vector<vector<int>> path(N-1, vector<int>(2));

        bool ok=true;
        for (int i=0; i<N-1; i++)
        {
            path[i][0] = tmp_order[i];
            path[i][1] = tmp_order[i+1];
            if (find(ab.begin(), ab.end(), path[i]) == ab.end() && find(ba.begin(), ba.end(), path[i]) == ba.end())
            {
                ok=false;
                break;
            }
        }
        if (ok) ans++;
        

    } while (next_permutation(order.begin(), order.end()));

    cout << ans << endl;
}