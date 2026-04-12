#include <bits/stdc++.h>

using namespace std;

int N, M;
vector <pair<int,long long>> D[100001];
long long D1[100001], D2[100001], W1[100001], W2[100001], G[100001], MOD=1000000007;

void Dij(int AA, int BB, long long DP[], long long W[])
{
    priority_queue <pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> Q;
    W[AA] = 0;
    DP[AA] = 1;
    Q.push({0, AA});
    for (int i = 1; i <= N; i++)
    {
        G[i] = 1;
    }
    while (Q.size() > 0)
    {
        while (Q.size() > 0 && G[Q.top().second] == 0)
        {
            Q.pop();
        }
        if (Q.size() == 0)
        {
            break;
        }
        int I = Q.top().second, a, b, wp;
        long long w = Q.top().first;
        G[I] = 0;
        Q.pop();
        for (int i = 0; i < D[I].size(); i++)
        {
            a = D[I][i].first;
            wp = D[I][i].second;
            if (W[I] + wp < W[a])
            {
                W[a] = W[I] + wp;
                DP[a] = DP[I];
                Q.push({W[a],a});
            }
            else if (W[I] + wp == W[a])
            {
                DP[a] += DP[I];
                DP[a] %= MOD;
            }
        }
    }
}

int main()
{
    int S, T;
    cin >> N >> M >> S >> T;
    int A[M], B[M], W[M];
    for (int i = 0; i < M; i++)
    {
        cin >> A[i] >> B[i] >> W[i];
        D[A[i]].push_back({B[i],W[i]});
        D[B[i]].push_back({A[i],W[i]});
    }
    for (int i = 1; i <= N; i++)
    {
        D1[i] = 0;
        D2[i] = 0;
        W1[i] = 200000000000000000;
        W2[i] = 200000000000000000;
    }
    Dij(S, T, D1, W1);
    Dij(T, S, D2, W2);
    long long Bu = D1[T] * D1[T], WW = W1[T], MI;
    Bu %= MOD;
    for (int i = 1; i <= N; i++)
    {
        if (W1[i] + W2[i] == WW && W1[i] == WW/2 && W2[i] == WW/2)
        {
            MI = ((D1[i] * D1[i]) % MOD) * ((D2[i] * D2[i]) % MOD);
            MI %= MOD;
            Bu -= MI;
            if (Bu < 0)
            {
                Bu += MOD;
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        int a=A[i], b=B[i];
        if (W2[a] < W1[a])
        {
            swap(a,b);
        }
        if (W1[a] + W2[b] + W[i] == WW && W1[a] < WW / 2 && W2[b] < WW / 2)
        {
            MI = ((D1[a] * D1[a]) % MOD) * ((D2[b] * D2[b]) % MOD);
            MI %= MOD;
            Bu -= MI;
            if (Bu < 0)
            {
                Bu += MOD;
            }
        }
    }
    cout << Bu;
    return 0;
}
