#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define vv vector<vi>
#define pb push_back
#define pi pair<int,int>
#define vp vector<pair<int,int> >
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define INF 1000000000
#define eps 1e-7
#define mod 1000000007
#define int ll
using namespace std;

int N,M;
int adj[10][10];

signed main(void) {
    vi path;
    cin>>N>>M;
    REP(i,1,N){
        path.pb(i);
        REP(j,1,N) {
            adj[i][j]=0;
        }
    }
    rep(i, M) {
        int a, b;
        cin>>a>>b;
        adj[a][b]=1;
        adj[b][a]=1;
    }
    int cnt=0;
    do {
        if(path[0]!=1) continue;
        bool flag=true;
        rep(i, path.size()-1) {
            if(adj[path[i]][path[i+1]]==0) {
                flag = false;
            }
        }
        if (flag) cnt++;
    } while(next_permutation(all(path)));
    cout << cnt << endl;
    return 0;
}