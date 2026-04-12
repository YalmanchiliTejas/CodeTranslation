#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A(100001);

void solve(){
    map<int, int> mp;
    int ans = 1;
    mp[A[1]] = 1;
    for(int i = 2; i <= N; ++i){
        if(A[i] > mp.begin()->first) {
            auto itr = mp.lower_bound(A[i]);
            itr--;
            itr->second--;
            if(itr->second <= 0) mp.erase(itr);
        }
        else ans++;
        mp[A[i]] += 1;
    }
    cout << ans;
}
int main(){
    cin >> N;
    for(int i = 1; i <= N; ++i){
        cin >> A[i];
    }
    solve();
    return 0;
}