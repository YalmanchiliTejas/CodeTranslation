#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        auto it = mp.lower_bound(a[i]);
        if(it != mp.begin()){
            it--;
            it -> second--;
            if(it -> second == 0) mp.erase(it);
        }
        mp[a[i]]++;
    }
    int ans = 0;
    for(auto i : mp) ans += i.second;
    cout << ans << endl;
}