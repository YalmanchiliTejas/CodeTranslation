#include <bits/stdc++.h>
#include<fstream>
#define ll long long
#define F first
#define S second
#define mp make_pair
#define mod 1000000007
#define All(v) v.begin(),v.end()

using namespace std;

string s[51];
vector<int> v[10];
int n;
bool vis[10];

int backtracking(int node,int cnt)
{
    if(cnt == n)
            return 1;

    ll res = 0;

    for(auto i:v[node])
    {
        if(!vis[i])
        {
            vis[i] = 1;
            res += backtracking(i,cnt+1);
            vis[i] = 0;
        }
    }
    return res;
}

int main()
{
    int m;
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
     vis[1] = 1;
    cout << backtracking(1,1) << endl;









    return 0;
}

