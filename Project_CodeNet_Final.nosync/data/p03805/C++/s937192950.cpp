#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

map<int, set<int>> routes;

int ans = 0;
int N;

void search(int position, vector<bool> reached, int depth)
{
    if (reached.at(position))
    {
        return;
    }
    reached.at(position) = true;

    if (depth == N)
    {
        ans++;
        return;
    }

    for (int next_position : routes[position])
    {
        int next_depth = depth + 1;
        vector<bool> reached2;
        copy(reached.begin(), reached.end(), back_inserter(reached2));
        search(next_position, reached2, next_depth);
    }
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
    search(0, reached, 1);

    cout << ans << endl;

    return 0;
}
