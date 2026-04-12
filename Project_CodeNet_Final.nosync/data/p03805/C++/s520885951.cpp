#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
using uint = unsigned  int;

using namespace std;

vector<vector<ll>> G(8);
vector<ll> c(1 << 9);
ll solve(uint v,vector<bool> didVisit){
    bool isAllVisit = true;
    for(int i = 0; i < didVisit.size(); i++){
        if(didVisit[i] == false){
            isAllVisit = false;
        }
    }
    if(isAllVisit){
        return 1;
    }else{
        ll sum = 0;
        for(int i = 0; i < G[v].size(); i++){
            ll nextId = G[v][i];
            if(didVisit[nextId]){
                continue;
            }
            didVisit[nextId] = true;
            sum += solve(nextId,didVisit);
            didVisit[nextId] = false;
        }
        return sum;
    }
}
int main() {
    ll N,M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<bool> didVisit = vector<bool>(N);
    for(int i = 0; i < N; i++){
        didVisit[i] = false;
    }
    didVisit[0] = true;
    cout << solve(0,didVisit) << endl;

}