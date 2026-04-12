#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <functional>
#include <map>
#include <queue>

#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)

using namespace std;
using ll = long long;
using P = pair<int, int>;
using TP = tuple<ll, ll, ll>;
ll MOD = 1e9+7;
//ll INF = 1LL<<40;
int INF = 1LL<<15;

int H, W;

int xv[4] = {-1, 1, 0, 0};
int yv[4] = {0, 0, -1, 1};

queue<TP> q,q2;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> mp(N);
    REP(i, M){
        int a, b;
        cin >> a >> b;
        a--;b--;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    queue<pair<int, vector<bool>>> q;
    vector<bool> used(N, false);
    used[0] = true;
    q.push(make_pair(0, used));
    int cnt = 0;
    while(!q.empty()){
        int i;
        tie(i, used) = q.front(); q.pop();
        for(auto e: mp[i]){
            //cout << e << endl;
            if(used[e] == false){
                used[e] = true;
                bool check = true;
                REP(i, N){
                    check &= used[i];
                }
                if(check){
                    cnt++;
                }else{
                    q.push(make_pair(e,used));
                }
                used[e] = false;
            }
        }
        
    }
    cout << cnt << endl;
    return 0;
}
