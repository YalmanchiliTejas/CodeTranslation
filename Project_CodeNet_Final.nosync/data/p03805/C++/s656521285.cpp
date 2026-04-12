#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> check(n+1, 0);
    vector<set<int>> map(n+1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        map[a].insert(b);
        map[b].insert(a);
    }
    vector<int>AR;
    int cnt =0;
    for (int i = 1; i <=n; i++)
    {
        AR.push_back(i);
        //cnt *=i;
    }

    do
    {
        bool F=1;
        for (int i = 0; i < n-1; i++)
        {         
                if(map[AR[i]].count(AR[i+1]));
                else
                {
                    F=0;
                    break;
                }
        }
        if(F) cnt++;
    } while (next_permutation(AR.begin()+1, AR.end()));
        
    cout << cnt << endl;
    
    return 0;
}

