#include<bits/stdc++.h>
using namespace std;
int A, B;
int d[11][11];
int targ[11][11];
vector<tuple<int, int, int> > ans;
bool valid(int x, int y, int c)
{
    for(int i=1; i<=A; ++i)
        for(int j=1; j<=B; ++j)
            if(d[i][j] > i*x+j*y+c)
                return false;
    for(int i=1; i<=A; ++i)
        for(int j=1; j<=B; ++j)
            targ[i][j] = min(targ[i][j], i*x+j*y+c);
    return true;
}
void find(int a, int b)
{
    for(int xpy = 0; xpy <= 100; ++ xpy)
    {
        for(int x = 0; x<=xpy; ++x)
        {
            int y = xpy - x;
            int c = d[a][b] - a*x-b*y;
            if(c<0) continue;
            if(valid(x, y, c))
            {
                ans.emplace_back(x, y, c);
                return;
            }
        }
    }
    puts("Impossible");
    exit(0);
}
int main()
{
    scanf("%d%d", &A, &B);
    for(int i=1; i<=A; ++i)
        for(int j=1; j<=B; ++j)
        {
            scanf("%d", &d[i][j]);
            targ[i][j] = 101;
        }
    for(int i=1; i<=A; ++i)
        for(int j=1; j<=B; ++j)
        {
            if(targ[i][j] != d[i][j])
                find(i, j);
        }
    int M = 0;
    int N = 2;
    for(auto t: ans)
    {
        int x, y, c; tie(x, y, c) = t;
        N += x + y + !!c - 1;
        M += x + y + !!c;
    }
    printf("Possible\n%d %d\n", N, M);
    int tp = 1;
    for(auto t: ans)
    {
        vector<pair<pair<int, int>,int>>V;
        int x, y, c; tie(x, y, c) = t;
        for(int i=0; i<x; ++i)
        {
            V.emplace_back(make_pair(tp, tp+1), -1);
            ++tp;
        }
        for(int i=0; i<y; ++i)
        {
            V.emplace_back(make_pair(tp, tp+1), -2);
            ++tp;
        }
        if(c)
        {
            V.emplace_back(make_pair(tp, tp+1), c);
            ++tp;
        }
        --tp;
        V[0].first.first = 1;
        V[V.size()-1].first.second = N;
        for(auto x: V)
        {
            printf("%d %d ", x.first.first, x.first.second);
            if(x.second == -2) puts("Y");
            else if(x.second == -1) puts("X");
            else printf("%d\n", x.second);
        }
    }
    printf("%d %d\n", 1, N);
    assert(N<=300);
    return 0;
}






