#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define MOD 1000000007
#define INF 1LL<<60

int N, M;
int S, T;
vector<vector<pair<long long, int>>> G;

vector<pair<long long, long long>> solve(int s){
    vector<pair<long long, long long>> dp(N);
    for(int i=0; i<N; i++)
        dp[i] = make_pair(INF, 0LL);
    dp[s] = make_pair(0, 1);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        auto tp = pq.top();
        pq.pop();
        long long c = tp.first;
        int t = tp.second;
        for(auto p : G[t]){
            long long d = p.first;
            int u = p.second;
            if(dp[u].first > c + d){
                dp[u] = make_pair(c+d, dp[t].second);
                pq.push(make_pair(c+d, u));
            }else if(dp[u].first == c+d){
                dp[u].second += dp[t].second;
                dp[u].second %= MOD;
            }
        }
    }
    return dp;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    cin >> S >> T;
    S--; T--;
    G.resize(N);
    vector<pair<int, int>> edges(M);
    map<pair<int, int>, int> mp;
    for(int i=0; i<M; i++){
        int U, V;
        long long D;
        cin >> U >> V >> D;
        U--; V--;
        G[U].push_back(make_pair(D, V));
        G[V].push_back(make_pair(D, U));
        edges[i] = make_pair(U, V);
        mp[make_pair(U, V)] = D;
        mp[make_pair(V, U)] = D;
    }
    auto dpS = solve(S);
    auto dpT = solve(T);

    for(auto &e : edges){
        if(dpS[e.first] > dpS[e.second])
            swap(e.first, e.second);
    }
    long long mn = dpS[T].first;
    long long ans = (dpS[T].second * dpT[S].second) % MOD;

    vector<long long> dpSS(N), dpTT(N);
    for(int i=0; i<N; i++){
        dpSS[i] = (dpS[i].second * dpS[i].second) % MOD;
        dpTT[i] = (dpT[i].second * dpT[i].second) % MOD;
    }

    for(int i=0; i<N; i++){
        if(dpS[i].first + dpT[i].first != mn) continue;
        if(2*dpS[i].first == mn){
            ans += (MOD - (dpSS[i] * dpTT[i]) % MOD) % MOD;
            ans %= MOD;
        }
    }
    for(auto &e : edges){
        int s = e.first;
        int t = e.second;
        if(dpS[s].first + dpT[s].first != mn) continue;
        if(dpS[t].first + dpT[t].first != mn) continue;
        if(dpS[s].first + mp[make_pair(s, t)] != dpS[t].first) continue;
        if(2*dpS[s].first < mn && 2*dpS[t].first > mn){
            ans += (MOD - dpSS[s] * dpTT[t] % MOD) % MOD;
            ans %= MOD;
        }
    }

    //for(auto &e : edges){
    //    int s = e.first;
    //    int t = e.second;
    //    if(dpS[s].first + dpT[s].first != mn || dpS[t].first + dpT[t].first != mn) continue;
    //    if(dpS[t].first != dpS[s].first + mp[make_pair(s, t)]) continue;
    //    long long dd = mp[make_pair(s, t)];
    //    if( (dpS[s].first <= dpT[t].first && dpT[t].first <= dpS[s].first + dd) ){
    //        //||
    //        //(dpT[t].first <= dpS[s].first && dpS[s].first < dpT[t].first + dd) ){
    //        cerr << s << " " << t << endl;
    //        ans += (MOD - (dpS[s].second * dpT[t].second) % MOD) % MOD;
    //        ans %= MOD;
    //    }
    //}
    cout << ans << endl;

    return 0;
}