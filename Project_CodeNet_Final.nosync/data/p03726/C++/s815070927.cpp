#include<bits/stdc++.h>

using namespace std;

int N;
vector < int > v[100009];

bool dfs (int nod, int tata)
{
    int cnt = 0;
    for (auto it : v[nod])
        if (it != tata)
            cnt += dfs (it, nod);
    if (cnt == 1) return 0;
    if (cnt > 1)
    {
        printf ("First\n");
        exit (0);
    }
    return 1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
bool ok = dfs (1, -1);
if (!ok) printf ("Second\n");
else printf ("First\n");
return 0;
}
