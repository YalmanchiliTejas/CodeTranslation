#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

vector<int> v[9];
bool seen[9];

ll dfs(int idx, int pat, int n,ll &cnt){
    if(pat==n-1){
        cnt++;
        return cnt;
    }
    int next;
    rep(i,v[idx].size()){
        next = v[idx][i];
        if(seen[next] == false){
            seen[next] = true;
            cnt = dfs(next,pat+1,n,cnt);
            seen[next] = false;
        }

    }
    return cnt;
}

int main(){
    int n, m;
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ll cnt=0 ;
    seen[1] = true;
    dfs(1,0,n,cnt);
    cout << cnt << endl;

    return 0;
}