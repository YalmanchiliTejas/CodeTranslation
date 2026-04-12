#include <bits/stdc++.h>
using namespace std;



int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    map<pair<int, int>, bool> mp;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        mp[make_pair(a, b)] = true;
    }

    vector<int> A(n);
    for(int i = 0; i < n; i++){
        A[i] = i;
    }

    int ans = 0;
    do{
        int now = A[0];
        if(now != 0) continue;
        bool f = false;
        for(int i = 1; i < n; i++){
            int to = A[i];
            int mi = min(now, to);
            int ma = max(now, to);
            if(mp[make_pair(mi, ma)]);
            else{
                f = true;
                break;
            }
            now = to;
        }
        if(!f) ans++;
    } while (next_permutation(A.begin(), A.end()));
    
    cout << ans << endl;

    return 0;
}