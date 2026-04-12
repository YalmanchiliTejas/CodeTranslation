#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll N, M;
    cin >> N >> M;
    VVL G(N+1);
    rep(i, 0, M){
        ll a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }   

    ll ans = 0;
    
    rep(i, 2, N+1){

        VB ini(N+1, false);
        queue<pair<ll, vector<bool>>> que;
        ini[1] = true;
        que.push({1, ini});
        while(!que.empty()){
            auto q = que.front();
            que.pop();
            bool f = false;
            if(q.first == i){
                f = true;
                rep(j, 1, N+1){
                    if(!q.second[j]) f = false;
                }
                if(f){
                    ans++;
                    cerr << i << endl;
                    continue;
                }else{
                    continue;
                }
            }
            
            
            
            for(auto g : G[q.first]){
                if(q.second[g]) continue;
                VB tmp(q.second);
                tmp[g] = true;
                que.push({g, tmp});
            }
        }
    }
    cout << ans << endl;
    return 0;
}