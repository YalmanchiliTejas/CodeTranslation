#include<iostream>
#include<vector>
#include<queue>
#define MOD 1000000007

using namespace std;

long long Dist[2][100005];
int Nr[2][100005];
vector<pair<int,int> > V[100005];
priority_queue<pair<long long,int> > Q;
pair<pair<int,int>,int> E[200005];

void getDist(int start, int cr)
{
    Dist[cr][start]=0;
    Nr[cr][start]=1;

    Q.push({0,start});
    while(!Q.empty())
    {
        long long cost=-Q.top().first;
        int nod=Q.top().second;
        Q.pop();

        if(cost!=Dist[cr][nod])
            continue;

        for(auto other:V[nod])
        {
            if(cost+other.second<Dist[cr][other.first])
            {
                Nr[cr][other.first]=0;
                Dist[cr][other.first]=cost+other.second;
                Q.push({-Dist[cr][other.first],other.first});
            }

            if(cost+other.second==Dist[cr][other.first])
                Nr[cr][other.first]=(Nr[cr][other.first]+Nr[cr][nod])%MOD;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m,s,t;
    cin>>n>>m>>s>>t;

    for(int i=1; i<=m; i++)
    {
        cin>>E[i].first.first>>E[i].first.second>>E[i].second;

        V[E[i].first.first].push_back({E[i].first.second,E[i].second});
        V[E[i].first.second].push_back({E[i].first.first,E[i].second});
    }

    for(int i=1; i<=n; i++)
        Dist[0][i]=Dist[1][i]=1000000000000000000LL;

    getDist(s,0);
    getDist(t,1);

    int rez=(1LL*Nr[0][t]*Nr[0][t])%MOD;
    long long cost=Dist[0][t];
    for(int i=1; i<=n; i++)
    {
        if(Dist[0][i]==Dist[1][i] && Dist[0][i]==cost/2)
            rez=(rez-(1LL*((1LL*Nr[0][i]*Nr[1][i])%MOD)*((1LL*Nr[0][i]*Nr[1][i])%MOD)%MOD)+MOD)%MOD;
    }

    for(int i=1; i<=m; i++)
    {
        int x=E[i].first.first;
        int y=E[i].first.second;
        int c=E[i].second;

        if(Dist[0][x]+Dist[1][y]+c>Dist[0][y]+Dist[1][x]+c)
            swap(x,y);

        if(Dist[0][x]+Dist[1][y]+c!=cost)
            continue;

        if(Dist[0][x]<(cost+1)/2 && Dist[0][x]+c>cost/2)
            rez=(rez-(1LL*((1LL*Nr[0][x]*Nr[1][y])%MOD)*((1LL*Nr[0][x]*Nr[1][y])%MOD)%MOD)+MOD)%MOD;
    }

    cout<<rez<<"\n";
    return 0;
}
