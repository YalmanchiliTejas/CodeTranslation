#include <bits/stdc++.h>

using namespace std;
ifstream fi("input.in");

const int NMAX = 100005;

struct punct
{
    int x, y, ord;
};

struct muchie
{
    int u, v, cost;
};

bool operator<(muchie a, muchie b)
{
    return a.cost > b.cost;
}

bool operator>(muchie a, muchie b)
{
    return a.cost < b.cost;
}

bool cX(punct a, punct b)
{
    return a.x < b.x;
}

bool cY(punct a, punct b)
{
    return a.y < b.y;
}


int n;
punct p[NMAX];
priority_queue <muchie> Q;
int par[NMAX];

int parinte(int x)
{
    if (par[x] == x)
        return x;
    return par[x] = parinte(par[x]);
}

void unite(int x, int y)
{
    par[parinte(x)] = parinte(y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y, p[i].ord = i;

    sort(p + 1, p + n + 1, cX);
    for (int i = 1; i < n; i++)
    {
        Q.push({p[i].ord, p[i + 1].ord, p[i + 1].x - p[i].x});
    }

    sort(p + 1, p + n + 1, cY);
    for (int i = 1; i < n; i++)
    {
        Q.push({p[i].ord, p[i + 1].ord, p[i + 1].y - p[i].y});
    }

    /*while (!Q.empty())
    {
        muchie curr = Q.top();
        Q.pop();
        cout << "de la " << curr.u << " la " << curr.v << ": " << curr.cost << "\n";
    }*/

    for (int i = 1; i <= n; i++)
        par[i] = i;

    int total = 0;
    while (!Q.empty())
    {
        muchie curr = Q.top();
        Q.pop();

        if (parinte(curr.u) != parinte(curr.v))
        {
            total += curr.cost;
            unite(curr.u, curr.v);
        }
    }
    cout << total;
    return 0;
}
