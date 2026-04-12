#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int N,M;
vector<vector<int>> G(8);
vector<bool> seen(8, false);
int dfs(int i, int cnt, vector<bool> &seen){
    if(cnt==N-1) return 1;
    seen[i] = true;

    int ans = 0;
    for(auto x: G[i]){
        if (seen[x]==true) continue;
        //cout << i<<": "<<x << endl;
        ans += dfs(x, cnt+1, seen);
    }
    seen[i]=false;
    return ans;

}

int main()
{
    cin >> N>>M;

    REP(i, M){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    cout << dfs(0,0,seen) << endl;

    

    

    return 0;
}