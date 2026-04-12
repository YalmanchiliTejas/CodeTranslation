#include <iostream>
#include <vector>

using namespace std;

typedef pair < int, int > PII;

const int NMAX = 2e5 + 5;

int N, M;

long long dp[NMAX];
long long sum[NMAX];

vector < PII > G[NMAX];

static inline void Read ()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for(int i = 1; i <= M; ++i)
    {
        int l = 0, r = 0, a = 0;
        cin >> l >> r >> a;

        G[r].push_back({l, a});

        sum[r] += a;
    }

    return;
}

class SegmentTree
{
    long long A[(NMAX << 2)];
    long long Lazy[(NMAX << 2)];

public:
    inline void Go (int Node, int a, int b)
    {
        if(Lazy[Node] == 0)
            return;

        if(a == b)
            return;

        A[2 * Node] += Lazy[Node];
        A[2 * Node + 1] += Lazy[Node];

        Lazy[2 * Node] += Lazy[Node];
        Lazy[2 * Node + 1] += Lazy[Node];

        Lazy[Node] = 0;

        return;
    }

    inline void Update_1 (int Node, int a, int b, int ua, int ub, long long X)
    {
        if(ua <= a && b <= ub)
        {
            Lazy[Node] += X;
            A[Node] += X;

            return;
        }

        Go(Node, a, b);

        int Mid = (a + b) >> 1;

        if(ua <= Mid)
            Update_1(2 * Node, a, Mid, ua, ub, X);

        if(ub > Mid)
            Update_1(2 * Node + 1, Mid + 1, b, ua, ub, X);

        A[Node] = max(A[2 * Node], A[2 * Node + 1]);

        return;
    }

    inline void Update_2 (int Node, int a, int b, int pos, long long X)
    {
        if(a == b)
        {
            A[Node] = X;

            return;
        }

        Go(Node, a, b);

        int Mid = (a + b) >> 1;

        if(pos <= Mid)
            Update_2(2 * Node, a, Mid, pos, X);

        if(pos > Mid)
            Update_2(2 * Node + 1, Mid + 1, b, pos, X);

        A[Node] = max(A[2 * Node], A[2 * Node + 1]);

        return;
    }

    inline long long Query (int Node, int a, int b, int qa, int qb)
    {
        if(qa <= a && b <= qb)
            return A[Node];

        Go(Node, a, b);

        int Mid = (a + b) >> 1;

        long long p1 = 0, p2 = 0;

        if(qa <= Mid)
            p1 = Query(2 * Node, a, Mid, qa, qb);

        if(qb > Mid)
            p2 = Query(2 * Node + 1, Mid + 1, b, qa, qb);

        return max(p1, p2);
    }
} T;

static inline void Solve ()
{
    for(int i = 1; i <= (N + 1); ++i)
    {
        for(auto it : G[i - 1])
        {
            int Left = it.first;
            int Right = i;

            long long Cost = it.second;

            if(Left >= Right)
                continue;

            T.Update_1(1, 1, N, Left, Right - 1, Cost);
        }

        if(i > 1)
            dp[i] = max(0LL, T.Query(1, 1, N, 1, i - 1));

        if(i <= N)
            T.Update_2(1, 1, N, i, dp[i]);

        dp[i] += sum[i];
    }

    cout << dp[N + 1] << '\n';

    return;
}

int main()
{
    Read();

    Solve();

    return 0;
}
