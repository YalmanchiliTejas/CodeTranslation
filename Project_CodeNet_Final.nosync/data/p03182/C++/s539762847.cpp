//thuanqvbn03
#include <bits/stdc++.h>

using namespace std;

const int MaxN = 200005;

struct Node
{
    int Left, Right, Val;
    bool operator<(const Node data) const
    {
        return (Right < data.Right);
    }
};

struct SegmentTree
{
    vector<long long> IT, Lazy;
    vector<int> Low, High;
    void InitTree(int x, int Left, int Right)
    {
        Low[x] = Left;
        High[x] = Right;
        IT[x] = 0;
        if (Left == Right)
        {
            return;
        }
        int Mid = (Left + Right) / 2;
        InitTree(x * 2, Left, Mid);
        InitTree(x * 2 + 1, Mid + 1, Right);
    }
    void Update(int x, int Left, int Right, long long Val)
    {
        if (Low[x] > Right || High[x] < Left)
        {
            return;
        }
        if (Low[x] >= Left && High[x] <= Right)
        {
            IT[x] += Val;
            Lazy[x] += Val;
            return;
        }
        Update(x * 2, Left, Right, Val);
        Update(x * 2 + 1, Left, Right, Val);
        IT[x] = max(IT[x * 2], IT[x * 2 + 1]) + Lazy[x];
    }
    void Init(int n)
    {
        IT.resize(4 * n + 5);
        Lazy.resize(4 * n + 5);
        Low.resize(4 * n + 5);
        High.resize(4 * n + 5);
        InitTree(1, 0, n + 1);
    }
};

int n, m;
Node a[MaxN];
SegmentTree SMT;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].Left >> a[i].Right >> a[i].Val;
    }
    sort(a + 1, a + m + 1);
    int j = 1;
    SMT.Init(n);
    for (int i = 1; i <= n; i++)
    {
        SMT.Update(1, i, i, SMT.IT[1]);
        while (a[j].Right == i)
        {
            SMT.Update(1, a[j].Left, a[j].Right, a[j].Val);
            j++;
        }
    }
    cout << max(0LL, SMT.IT[1]);
    return 0;
}