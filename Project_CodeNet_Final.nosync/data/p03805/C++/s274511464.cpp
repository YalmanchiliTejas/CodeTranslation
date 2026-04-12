#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> r(n, vector<bool>(n, false));
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        r[a][b] = true;
        r[b][a] = true;
    }
    vector<int> e(n-1);
    rep(i, n-1)e[i] = i+1;
    ll ans = 0;
    do{
        bool ok = true;
        if(!r[0][e[0]])ok = false;
        for(int i = 1; i < n-1; i++){
            if(!r[e[i-1]][e[i]])ok = false;
        }
        if(ok)ans++;
    }while(next_permutation(all(e)));
    cout << ans << endl;
}      