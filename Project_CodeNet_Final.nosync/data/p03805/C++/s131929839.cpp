#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, m, cnt;
int a[10] = {0, 1};
vector<int> v[10];

void f(int p, int q)
{
    if(q == n)
    {
        cnt++;
        return;
    }
    for(int i = 0; i < v[p].size(); i++)
    {
        if(!a[v[p][i]]) {
            a[v[p][i]]++;
            f(v[p][i], q + 1);
            a[v[p][i]]--;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    f(1, 1);
    printf("%d", cnt);
    return 0;
}
