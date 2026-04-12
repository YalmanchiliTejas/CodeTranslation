#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <numeric>
using namespace std;
typedef long long int lli;
const lli inf = 1e18;

lli knapsack_dp(vector<lli> &cost, vector<lli> &value, lli capacity){
    vector<lli> dp(capacity+1, 0);
    for(int i=0; i<(int)cost.size(); i++){
        for(int j=0; j<capacity; j++){
            if(j+cost[i] > capacity) break;
            dp[j+cost[i]] = max(dp[j+cost[i]], dp[j]+value[i]);
        }

    }
    return *max_element(dp.begin(), dp.end());
}

int main(){
    lli n,m,w,t;
    cin >> n >> m >> w >> t;
    
    map<string, pair<lli,lli>> s2cv;
    for(int i=0; i<m; i++){
        string s;
        lli c,v;
        cin >> s >> c >> v;
        s2cv[s] = {c, v};
    }
    vector<vector<pair<lli,lli>>> cv(n);
    vector<lli> x(n),y(n);
    for(int i=0; i<n; i++){
        int item;
        cin >> item >> x[i] >> y[i];
        for(int j=0; j<item; j++){
            string name;
            lli price;
            cin >> name >> price;
            auto ret = s2cv[name];
            cv[i].emplace_back(ret.first, ret.second -price);
        }
    }

    vector<lli> mindist(1<<n, inf);
    vector<lli> maxvalue(1<<n, 0);
    for(int i=1; i<(1<<n); i++){
        vector<int> idxs;
        for(int j=0; j<n; j++){
            if(i>>j&1) idxs.push_back(j);
        }
        do{
            lli dist = abs(x[idxs[0]])+abs(y[idxs[0]]) +abs(x[idxs.back()])+abs(y[idxs.back()]);
            for(int j=0; j<(int)idxs.size()-1; j++){
                dist += abs(x[idxs[j]]-x[idxs[j+1]]) +abs(y[idxs[j]]-y[idxs[j+1]]);
            }
            mindist[i] = min(mindist[i], dist);
        }while(next_permutation(idxs.begin(), idxs.end()));

        vector<lli> cost, value;
        for(int j: idxs){
            for(auto &p: cv[j]){
                cost.push_back(p.first);
                value.push_back(p.second);
            }
        }
        maxvalue[i] = knapsack_dp(cost, value, w);
    }

    cout << knapsack_dp(mindist, maxvalue, t) << endl;
    return 0;
}

