#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define MAX_N 40
#define INF 100000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;

int n, m, k;
vector<int> d;
map<int,int> rev;
int e[100][100];
int dp[(1<<16)];
queue<int> que;

int main(){
    cin >> n >> m >> k;
    rep(i,(1<<16)) dp[i] = INF;
    rep(i,m){
        int D;
        cin >> D;
        d.push_back(--D);
        rev[D] = i;
    }
    rep(i,n) rep(j,k){
        int v;
        cin >> v; v--;
        e[i][j] = v;
    }
    int st = 0;
    rep(i,d.size()){
        st += (1<<i);
    }
    dp[st] = 0;
    que.push(st);
    while(!que.empty()){
        int p = que.front();
        que.pop();
        rep(i,k){
            int nxt = 0;
            rep(j,d.size()){
                if(p&(1<<j)){
                    int to = e[d[j]][i];
                    if(rev.count(to)){
                        nxt |= (1<<rev[to]);
                    }
                }
            }
            if(dp[nxt] == INF){
                dp[nxt] = dp[p]+1;
                que.push(nxt);
            }
        }
    }
    cout << dp[0] << endl;
}