#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main()
{
    int n;
    cin >> n;

    vector<ull> a(n);
    for(int i=0; i<n; i++){
        ull t;
        cin >> t;
        a.at(i) = t;
    }
    sort(a.begin(), a.end());

    // 偶数→1パターン
    // 奇数→2パターン：中心3つの振り分けの差

    ull ans = 0;
    if(n%2==0){
        ans = a.at(n/2) - a.at(n/2-1);
        for(int i=0; i<n/2-1; i++){
            ans += a.at(n-1-i) * 2;
            ans -= a.at(i) * 2;
        }
    }
    else{
        long long mid1 = a.at(n/2+1) + a.at(n/2) - a.at(n/2-1) * 2;
        long long mid2 = a.at(n/2+1) * 2 - a.at(n/2) - a.at(n/2-1);
        ans = (ull)max(mid1, mid2);
        for(int i=0; i<n/2-1; i++){
            ans += a.at(n-1-i) * 2;
            ans -= a.at(i) * 2;
        }
    }

    cout << ans << endl;
    return 0;
}
