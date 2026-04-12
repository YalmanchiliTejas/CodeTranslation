///not today

#include<bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x).size()
#define pb push_back
#define ll long long
#define xmax(x, y) (x) = max((x), (y))
#define xmin(x, y) (x) = min((x), (y))
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define int long long
#define pipii pair<int, pair<int, int> >
#define pf push_front

bool ans = false;
const int maxn = 1000* 100 + 5;
vector <int> aj[maxn];
bool mrk[maxn], r[maxn];
int pr[maxn];

void dfs(int v){
    mrk[v] = true;
    for(int i = 0; i < SZ(aj[v]); i ++){
        int u = aj[v][i];
        if(!mrk[u]){
            pr[u] = v;
            dfs(u);
        }
    }
    if(!r[v]){
        if(r[pr[v]] or v == 0)
            ans = true;
        else{
            r[pr[v]] = true;
            r[v] = true;
        }
    }
    return;
}

int32_t main(){
    int n;
    cin >>n;
    for(int i = 1; i < n; i ++){
        int u, v;
        cin >>u >>v;
        u --;
        v --;
        aj[u].pb(v);
        aj[v].pb(u);
    }
    dfs(0);
    if(ans)
        cout <<"First" <<endl;
    else
        cout <<"Second" <<endl;
}
