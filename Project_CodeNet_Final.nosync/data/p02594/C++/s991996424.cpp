/**
 *    author:  Sushil Sekhar Satapathy
 *    created: 30.Jul.2020 18:38:25
 *
 *    Only the ladder is real!! The climb is all there is.
 *
**/

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long int
#define mod 1000000007
#define vi vector<int>
#define pint pair<int,int>
#define vint vector<vector<int>>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 1e6+5;
int A[N];

unordered_map<int, list<int>> mp;

void addEdge(int u, int v)
{
    mp[u].push_back(v);
    //mp[v].push_back(u);
}

int solve(int n, int src)
{
    vi dist(n, INT_MAX);
    //vi look(n, INT_MAX);
    //priority_queue<int> pq;
    queue<int> q;
    set<int> s;

    q.push(src);
    dist[src] = 0;
    s.insert(src);
    //look[src] = 0;
    //pq.push(src);
    int i, left = 0;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(auto neigh: mp[curr])
        {
            if(dist[neigh] == INT_MAX)
            {
                q.push(neigh);
                dist[neigh] = dist[curr] + 1;
                s.insert(neigh);
                //pq.push(neigh);

                /*int top = pq.top();
                int minimum = INT_MAX;

                for(i=neigh; i<=top; i++)
                    minimum = min(minimum, dist[i]);
                if(dist[neigh] > minimum)
                    dist[neigh] = minimum;*/
                /*if(neigh >= left)
                {
                    for(i=left+1;i<=neigh;i++)
                        look[i] = min(look[i], dist[neigh]);
                    left = neigh;
                }
                else
                    dist[neigh] = min(dist[neigh], look[neigh]);*/

                auto ub = upper_bound(s.begin(), s.end(), neigh);
                if(ub != s.end())
                    dist[neigh] = min(dist[neigh], dist[*ub]);
            }
        }
    }

    int sum = 0;
    for(auto x: dist)
    {
        //cout<<x<<" ";
        sum += x;
    }
    //cout<<endl;
    return sum;
}

int32_t main()
{
    //code
	IOS;
	//#ifndef ONLINE_JUDGE
    //freopen("alchemy_input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif

    int t,n,m,a,b,x,y,i,j,z;
    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>x;
        if(x>=30) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

	return 0;
}
