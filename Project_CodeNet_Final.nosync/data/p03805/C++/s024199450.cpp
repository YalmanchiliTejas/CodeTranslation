#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1000000000 + 7;

bool G[9][9];

int main()
{
   
    
    int a, b, c, N, M;

    scanf("%d %d", &N, &M);

    while(M--)
    {
        scanf("%d %d", &b, &c);
        G[b][c] = G[c][b] = true;
    }

    vector<int>v;

    for(int i = 2; i <= N; i++)
    {
        v.push_back(i);
    }

    int ans = 0;

    do
    {
        int i;
        int j = 1;
        for(i = 0; i < N - 1; i++)
        {
            if(!G[j][ v[i] ])
            {
                break;
            }
            j = v[i];
        }
        if(i == N - 1)
        {
            ans++;
        }
    }while(next_permutation(v.begin(), v.end()));

    cout<<ans<<endl;
    

    return 0;
}
