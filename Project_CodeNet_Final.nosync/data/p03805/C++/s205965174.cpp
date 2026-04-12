#include <bits/stdc++.h>
using namespace std;
#define fo(x, n) for(int i = x; i <= n; i++)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector <int> vi;
const int MOD = 1e9 + 7;
vi a[10];
int n, m;
void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vi p(n);
    fo(1, n) p[i - 1] = i;
    int cnt = 0;
    do{
        int flag = 1;
        for(int i = 1; i < n; i++){
            bool ok = false;
            for(int x : a[p[i - 1]]){
                if(x == p[i]){
                    ok = true;
                    break;
                }
            }
            if(!ok){
                flag = 0;
                break;
            }
        }
        cnt += flag;
    }
    while(next_permutation(p.begin() + 1, p.end()));
    cout << cnt;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
	int T = 1;
    //cin >> T;
    fo(1, T){
        solve();
    }
}

