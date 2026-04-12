#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    bool path[n][n] = {};
    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        path[a - 1][b - 1] = true;
        path[b - 1][a - 1] = true;
    }
    int perm[n];
    for(int i = 0;i < n;i++)
    {
        perm[i] = i + 1;
    }
    int ans = 0;
    do
    {
        if(perm[0] != 1)
        {
            break;
        }
        bool flag = true;
        for(int i = 1;i < n;i++)
        {
            if(!path[perm[i - 1] - 1][perm[i] - 1])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            ans++;
        }
    } while (next_permutation(perm,perm + n));
    cout << ans << "\n";
    
    return 0;
}