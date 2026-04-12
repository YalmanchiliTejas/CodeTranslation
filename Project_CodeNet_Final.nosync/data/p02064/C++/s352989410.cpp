#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;


signed main(){
    
    i64 n, s, t;
    cin >> n >> s >> t;
    --s, --t;
    
    auto f = [&](i64 u, i64 v){
        cout << "? " << u + 1 << " " << v + 1 << endl;
        i64 x;
        cin >> x;
        return x;
    };
    
    vector<i64> r_s(n), r_t(n);
    i64 st = i64(1e18);
    for(int i = 0; i < n; ++i){
        r_s[i] = (i == s ? 0 : f(i, s));
        r_t[i] = (i == t ? 0 : f(i, t));
        st = min(st, r_s[i] + r_t[i]);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
    for(int i = 0; i < n; ++i)
        if(r_s[i] + r_t[i] == st && s != i)
            que.emplace(r_s[i], i);
        
    vector<int> ans(1, s);
    while(!que.empty()){
        i64 len, pos;
        tie(len, pos) = que.top();
        que.pop();
        i64 f1 = f(pos, ans.back());
        if(r_s[ans.back()] + f1 == r_s[pos] && f1 + r_s[ans.back()] + r_t[pos] == st)
            ans.emplace_back(pos);
    }
    cout << "!";
    for(auto& x : ans)
        cout << " " << x + 1;
    cout << endl;
}
