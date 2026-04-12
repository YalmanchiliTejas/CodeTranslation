#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long i64;
typedef long double ld;
typedef pair<i64,i64> P;
#define rep(i,s,e) for(int i = (s);i <= (e);i++)

int n;
int m;

vector<int> edges[10];
int vis[10];

int rec(int s,int cou = 1)
{
    int ans = 0;
    vis[s] = 1;

    if(cou == n) ans += 1;

    for(int to : edges[s])
    {
        if(vis[to] == 0)
        {
           ans += rec(to,cou + 1); 
        }
    }


    vis[s] = 0;
    return ans;    
}

int main()
{
    cin >> n >> m;
    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);   
        edges[b].push_back(a);
    }

    cout << rec(1) << endl;
}