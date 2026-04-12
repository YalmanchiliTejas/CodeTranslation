#include "bits/stdc++.h"
#define REP(i, n, N) for(ll i=(n); i<(N); i++)
#define RREP(i, n, N) for(ll i=(N-1); i>=(n); i--)
#define LREP(lst,itr) for(auto itr = lst.begin(); itr != lst.end(); ++itr)
#define CK(n, a, b) ((a)<=(n)&&(n)<(b))
#define ALL(v) (v).begin(),(v).end()
#define MCP(a, b) memcpy(b,a,sizeof(b))
#define P(s) cout<<(s)<<endl
#define P2(a, b) cout<<(a)<<" "<<(b)<<endl
#define P3(a, b, c) cout<<(a)<<" "<<(b)<<" "<<(c)<<endl
#define V2(T) vector<vector<T>>
typedef long long ll;
using namespace std;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
int main(){
    int N,M;
    cin >> N >> M;
    if(!M){
        P(0);
        return 0;
    }
    vector<int> edges[N];
    REP(i,0,M){
        int a,b;
        cin >> a >> b;
        a--;b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    queue<pair<int, vector<int>>> que;
    vector<int> nodes(N,0);
    nodes[0]=1;
    que.push(make_pair(0, nodes));

    int ans=0;
    while(!que.empty()){
        pair<int, vector<int>> node = que.front();

        // P(node.first);
        // REP(i,0,N){
        //     cout << node.second[i];
        //     if(i!=N-1) cout << " ";
        // }
        // cout << endl;

        que.pop();
        if(accumulate(ALL(node.second),0)==N){
            ans++;
            continue;
        }
        for(auto e : edges[node.first]){
            if(node.second[e]==1){
                continue;
            }else{
                node.second[e]=1;
                que.push(make_pair(e, node.second));
                node.second[e]=0;
            }
        }
    }

    P(ans);
}