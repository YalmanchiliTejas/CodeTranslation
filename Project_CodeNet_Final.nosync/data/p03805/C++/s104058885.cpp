#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef long long int ll;
typedef vector< pair<int,int> > vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long int> vll;
typedef pair<int,int> pii;

const ll INF= ll (1e18);
const int MOD= 1e9+7;

int main()
{
    vi v;
    int graph[10][10]={0};

    int n,m;
    cin>>n>>m;

    while(m--)
    {
        int u,v;
        cin>>u>>v;

        graph[u][v]=1;
        graph[v][u]=1;
    }

    for(int i=0;i<n;i++)
        v.pb(i+1);

 int cnt=0;

    do
    {
        int flag=0;

        if(v[0]!=1)
            break;

        for(int i=0;i<=n-2;i++)
        {
            if(graph[v[i]][v[i+1]]!=1)
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
            cnt++;

    }while(next_permutation(v.begin(),v.end()));

    cout<<cnt<<endl;


    return 0;
}
