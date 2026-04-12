#include <bits/stdc++.h>
using Int = long long;
using namespace std;
int main(){
    int N; cin >> N;
    vector<Int>v(N);
    for(auto& e : v) cin >> e;
    reverse(v.begin(),v.end());
    Int ans = 0;
    multiset<Int>S;
    for(int i = 0; i < N; ++i){
        auto itr = S.lower_bound(v[i] + 1);
        if(itr == S.end()){
            ++ans;
        } else {
            S.erase(itr);
        }
        S.insert(v[i]);
    }
    cout << ans << endl;
}

