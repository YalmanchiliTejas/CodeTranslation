#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ll((x).size())
#define OUT(x) cout << (x) << endl
typedef long long ll;
typedef vector<ll> V;
typedef vector< vector<ll> > VV;
typedef pair<ll, ll> P;
typedef map<string, ll> M;
typedef unordered_map<ll, ll> HM;
typedef set<ll> S;
typedef multiset<ll> MS;
typedef queue<ll> Q;

int main(){
    ll n,m; cin>>n>>m;
    ll g[n][n];
    for(ll i=0; i<m; i++){
        ll a,b; cin>>a>>b;
        a--; b--;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    ll path[n];
    for(ll i=0; i<n; i++)
        path[i] = i;
    ll ans = 0;
    do{
        if(path[0] != 0)
            continue;
        bool flag = true;
        for(ll i=1; i<n; i++){
            if(!(g[path[i-1]][path[i]]==1))
                flag = false;
        }
        if(flag)
            ans++;
    }while(next_permutation(path, path+n));
    OUT(ans);
}