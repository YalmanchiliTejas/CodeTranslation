#include <bits/stdc++.h>
using namespace std;

int main(){    
    int n, a[100000];
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    map<int,int> mp;
    mp[a[0]] = 1;
    for(int i=1;i<n;i++){
        auto it = mp.lower_bound(a[i]);
        if(it != mp.begin()){
            --it;
            (it->second)--;
            if(it->second == 0) mp.erase(it);
        }
        mp[a[i]]++;
    }

    int ans = 0;
    for(auto m : mp) ans += m.second;
    cout << ans << endl;
    
    return 0;
}