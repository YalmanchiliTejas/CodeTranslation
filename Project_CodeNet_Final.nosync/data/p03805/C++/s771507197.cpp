#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)
const ll INF = 1LL << 60;

vector<vector<int>> g;
bool seen[9][9];

int main(){
    int n,m; 
    cin >> n >> m;
    vector<int> v(n);
    g.resize(n);
    rep(i,n){
        v[i] = i;
    }
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    do{
        bool can = false;
        for (int i = 0;i < n-1;i++){
            bool f = false;
            for (auto nx:g[v[i]]){
                if (nx == v[i+1]){
                    f = true;
                }
            }
            if (!f) break; 
            if (i == n-2 && f) can = true;
        }
        if (can) ans++;
        //if (can){
        //    rep(i,n) cout << v[i];
        //    cout << endl;
        //}

    }while(next_permutation(v.begin()+1,v.end()));
    
    cout << ans << endl;
    


    
    
    return 0;
}