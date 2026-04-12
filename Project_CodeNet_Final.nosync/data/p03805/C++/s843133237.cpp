#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0;i < n;i++)
#define rev(i, n) for(int i = n;i >= 0;i--)
#define Rep(i, m, n) for(int i = m;i < n;i++)
#define repeatrev(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define INF 999999999
#define itn int
const int MAX = 10;


using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
typedef priority_queue<int> Pr;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

vector<int> G[2 * MAX]; //次に行くところを管理する
bool used[2 * MAX];

int dfs(int v, int N){
    bool all_visited = true;
    for(int i = 1; i <= N; i ++) if(!used[i]) all_visited = false;
    if(all_visited) return 1;
    int ans = 0;
    for(int s: G[v]){ //cout << s << endl;
        if(used[s]) continue;
        used[s] = true;
        ans += dfs(s, N);
        used[s] = false;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    rep(i, MAX) used[i] = false;
    int n, m;
    cin >> n >> m;
    rep(i, m){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    used[1] = true;
    cout << dfs(1, n) << endl;


}