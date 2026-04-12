#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,vector<bool>>P;

signed main(void){
    int n,m; cin >> n >> m;
    vector<vector<int>> g(n);
    int ans = 0;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b; a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<g[i].size();j++){
    //         cout << g[i][j] << ' ';
    //     }cout << endl;
    // }cout << endl;

    queue<P>q;
    vector<bool>initial(n,false);
    initial[0]=true;
    q.push(P{0,initial});
    while(q.size()!=0){
        P tmp = q.front();q.pop();
        int e = tmp.first;
        vector<bool>already = tmp.second;

        // cout << e << ' ';
        // for(int i=0;i<already.size();i++) cout << already[i] << ' ';
        // cout << endl;

        bool change = false;
        for(int i=0;i<g[e].size();i++){
            if(already[g[e][i]]==false){
                change = true;
                vector<bool>next_already;
                copy(already.begin(), already.end(), back_inserter(next_already) );
                next_already[g[e][i]]=true;
                q.push(P{g[e][i],next_already});
            }
        }
        if(change == false){
            bool ok = true;
            for(int i=0;i<already.size();i++){
                if(already[i]==false){
                    ok = false;
                    break;
                }
            }
            if(ok == true) ans++;
        }
    }
    cout << ans << endl;
    return 0;

}
