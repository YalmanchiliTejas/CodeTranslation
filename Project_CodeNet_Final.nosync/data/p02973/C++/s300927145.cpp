#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int n;
int Arr[N];
int Seg[5 * N];

void Update (int idx, int val, int Node = 1, int L = 1, int R = n)
{
    if (idx > R || idx < L) return;
    if (L == R) {
        Seg[Node] = val;
        return;
    }

    int Mid = L + R >> 1;
    Update (idx, val, Node << 1, L, Mid);
    Update (idx, val, Node << 1 | 1, Mid + 1, R);

    Seg[Node] = max(Seg[Node << 1], Seg[Node << 1 | 1]);
}

int Query (int i, int j, int Node = 1, int L = 1, int R = n)
{
    if (i > R || j < L)    return -1e9;
    if (L >= i && R <= j)
        return Seg[Node];

    int Mid = L + R >> 1;
    int Q1 = Query (i, j, Node << 1, L, Mid);
    int Q2 = Query (i, j, Node << 1 | 1, Mid + 1, R);

    return max(Q1, Q2);
}

bool cmp (pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;

    vector <pair<int, int>> v;
    for (int i = 1; i <= n; i++) {
        cin >> Arr[i];
        v.push_back({Arr[i], i});
    }

    sort(v.begin(), v.end(), cmp);
 
    int Max = 0;
    for (int i = 0; i < n; i++)
    {
        int idx = v[i].second;
        int cur = (idx == 1 ? 0 : Query(1, idx - 1));
        Max = max(Max, cur + 1);
        Update(idx, cur + 1);
    }

    cout << Max << '\n';

    return 0;
}
