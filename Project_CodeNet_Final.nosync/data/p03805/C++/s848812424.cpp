/*
tags:[贪心][排序][预处理]
贪心地选取一些连续的夏日，在这些连续的夏日里使用冬胎。
a[i]: 第i个冬日，出现在第几天。
b[i] = a[i+1] - a[i] － 1表示两个相邻的冬日之间有多少个连续的夏日。
显然，我们希望连续的夏日时间越短越好，故对b从小到大排序。
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector> 
using namespace std;
const int NICO = 200000 + 10;
vector<int> vec[100];int n, m;
int res = 0, a[10];
void dfs(int used[], int x)
{
    int ok = 1;used[x] = 1;
    for(int i=1;i<=n;i++)
    {
        if(!used[i]) ok = 0;
    }
    if(ok) {res ++;return;}
    for(int i=0;i<vec[x].size();i++)
    {
        int cur = vec[x][i];
        if(used[cur]) continue;
        int b[10];for(int j=1;j<=n;j++) b[j]=used[j];
        dfs(b, cur);
    }
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int a, b;cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs(a, 1);
    cout << res << endl;
}