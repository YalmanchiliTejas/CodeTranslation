#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

map<int, set<int>> routes;

int ans = 0;
int N;

int search(int position, vector<bool> reached)
{
    bool all_visited = true;
    rep(i, N)
    {
        if (reached.at(i) == false)
        {
            all_visited = false;
        }
    }

    if (all_visited)
    {
        return 1;
    }

    int ret = 0;

    for (int next_position : routes[position])
    {
        if (reached.at(next_position))
        {
            continue;
        }
        reached.at(next_position) = true;
        ret += search(next_position, reached);
        reached.at(next_position) = false;
    }

    return ret;
}

int main()
{
    int M;
    cin >> N >> M;

    vector<int> a(M);
    vector<int> b(M);
    rep(i, M) cin >> a.at(i) >> b.at(i);
    rep(i, M)
    {
        a.at(i)--;
        b.at(i)--;
    }

    rep(i, M)
    {
        routes[a.at(i)].insert(b.at(i));
        routes[b.at(i)].insert(a.at(i));
    }
    vector<bool> reached(N, false);
    reached.at(0) = true;
    
    cout << search(0, reached) << endl;

    return 0;
}
