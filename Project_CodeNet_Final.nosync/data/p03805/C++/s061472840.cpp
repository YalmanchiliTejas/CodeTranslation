#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
#define INF 1e9
#define DEBUG(x) cout<<"debug: "<<x<<endl

int n, m;
int main() {
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n));
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--;b--;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    vector<int> convinations;
    rep(i, 0, n) convinations.push_back(i);

    int ans = 0;

    int size = convinations.size();
    do{
        if(convinations[0] != 0) continue;
        bool ok = true;
        rep(i, 0, size-1){
            int a = convinations[i];
            int b = convinations[i+1];
            if(!graph[a][b]) ok = false;
        }
        if(ok) ans++;
    }while(next_permutation(ALL(convinations)));

    cout << ans << endl;
    return 0;
}
