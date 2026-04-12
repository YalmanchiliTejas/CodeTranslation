#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

long long MOD = 1000000007LL;

template<class T>
vector<T> dijkstra(vector<vector<int>> E, vector<vector<T>> W, int s, T inf, vector<long long> &pat)
{
    int n = (int)E.size();

    for (int i=0; i<n; i++)
        pat[i] = 0;

    vector<T> D(n, inf);
    typedef pair<T,int> P;
    priority_queue<P,vector<P>,greater<P>> Q;

    D[s] = T();
    pat[s] = 1;
    Q.push(make_pair(D[s], s));

    while (!Q.empty())
    {
        long long d = Q.top().first;
        int p = Q.top().second;
        Q.pop();
        if (d > D[p])
            continue;
        for (int i=0; i<(int)E[p].size(); i++)
        {
            int t = E[p][i];
            if (d+W[p][i] < D[t])
                D[t] = d+W[p][i],
                pat[t] = 0LL,
                Q.push(make_pair(D[t], t));
            if (d+W[p][i]==D[t])
                pat[t] = (pat[t]+pat[p])%MOD;
        }
    }
    return D;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;
    cin>>N>>M;
    int S, T;
    cin>>S>>T;
    S--, T--;
    vector<vector<int>> E(N);
    vector<vector<long long>> D(N);
    for (int i=0; i<M; i++)
    {
        int u, v;
        long long d;
        cin>>u>>v>>d;
        E[u-1].push_back(v-1);
        E[v-1].push_back(u-1);
        D[u-1].push_back(d);
        D[v-1].push_back(d);
    }
    vector<long long> DS(N), DT(N), PS(N), PT(N);
    long long oo = 10000000000LL*N;
    DS = dijkstra(E, D, S, oo, PS);
    DT = dijkstra(E, D, T, oo, PT);

    long long ans = PS[T]*PS[T]%MOD;
    for (int i=0; i<N; i++)
    for (int j=0; j<(int)E[i].size(); j++)
        if (DS[i] + D[i][j] + DT[E[i][j]] == DS[T])
            if (DS[i]*2 < DS[T] && DS[T] < DS[E[i][j]]*2)
                ans -= PS[i]*PS[i]%MOD*PT[E[i][j]]%MOD*PT[E[i][j]]%MOD;
    for (int i=0; i<N; i++)
        if (DS[i] + DT[i] == DS[T] && DS[i]*2==DS[T])
            ans -= PS[i]*PS[i]%MOD*PT[i]%MOD*PT[i]%MOD;
    cout<<(ans%MOD+MOD)%MOD<<endl;
}
