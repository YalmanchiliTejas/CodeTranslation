#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int Sum[100005], Leaf[100005];
vector <int> G[100005];
queue <int> Q, Q2;
bool Use[100005];
int Grade[100005];
void Read()
{
    cin >> N;
    for(int i = 1; i <= N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        ++Grade[a];
        ++Grade[b];
        G[a].push_back(b);
        G[b].push_back(a);
    }
    //int cnt = 0;
    for(int i = 1; i <= N; i++)
        if(G[i].size() == 1)
        {
            Q.push(i);
        }
    int cnt = 0;
        while(!Q.empty())
        {
        int node = Q.front();


        Q.pop();
        if(Use[node] == 1)
            continue;
        ++cnt;
        if(Grade[node] == 0)
        {
            cout << "First\n";
            return;
        }
        Use[node] = 1;
        while(G[node].size() > 0 && Use[G[node].back()] == 1)
            G[node].pop_back();
        int neighb = G[node].back();
        --Grade[neighb];
        Use[neighb] = 1;
        for(int i = 0; i < G[neighb].size(); i++)
        {
            int n = G[neighb][i];
            if(Use[n] == 0)
            {
                --Grade[n];
                if(Grade[n] == 1)
                    Q.push(n);
            }
        }
        }

    cout << "Second\n";
}
int main()
{
    Read();
    return 0;
}
