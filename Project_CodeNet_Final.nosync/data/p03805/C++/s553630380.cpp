#include <bits/stdc++.h>
using namespace std;

//#define int long long
//struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
const int MOD = 1e9 + 7;
using intpair = pair<int, int>;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((int)((a) + (b) - 1)/(int)(b))

signed main(){
    int n, m;
    cin >> n >> m;
    vector<set<int>> graph(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    
    vector<int> per(n-1);
    rep(i,n-1) per[i] = i+1;
    
    int ans = 0;
    do{
        int now = 0;
        for(int next : per){
            if(!graph[now].count(next)){
                break;
            }else{
                now = next;
            }
        }
        if(now == per.back()) ans++;
    }while(next_permutation(ALL(per)));
    
    cout << ans << endl;
}