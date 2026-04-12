#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, j, n) for (int i = j; i < (n); ++i)
#define SORT(a) sort(a.begin(), a.end())
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

vi to[100100];
vi flag(100100);

int n, m;
int bfs(int u, int count)
{
    if(flag[u]==1) return 0;
    if(count ==n) return 1;

    flag[u]=1;
    int ans = 0;
    for(int v : to[u]){
        ans += bfs(v,count+1);
    }
    flag[u]=-1;
    return ans;
}

int main()
{
    cin >> n >> m;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a); 
        flag[i] = -1;       
    }
    ;
    cout << bfs(0,1) <<endl;
}