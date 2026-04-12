#include <bits/stdc++.h>
using namespace std;
//16:05
int N,M;
int f[8][8] = {0};

int search(vector<bool> &used,int i,int t)
{
    int ans = 0;
    t++;
    if(t == N)
    {
        t--;
        return 1;
    }
    used[i] = true;
    for(int j = 0;j<N;j++)
    {
        if(!used[j] && f[i][j] != 0)
        {
            ans += search(used,j,t);
        }
    }
    used[i] = false;
    t--;
    return ans;
}
int main()
{
    cin >> N >> M;
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        f[a][b] = 1;
        f[b][a] = 1;
    }
    
    vector<bool> used(N,false);

    int count = search(used,0,0);
    
    cout <<count << endl;
 
    return 0;
    
}