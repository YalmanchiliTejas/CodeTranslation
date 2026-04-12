#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<long long> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());

    long long ans1 = 0;
    for(int i = 0; i < n/2-1; i++){
        ans1 += v[i] * 2;
    }
    ans1 += v[n/2-1];
    if(n%2 == 0) ans1 -= v[n/2];
    else ans1 += v[n/2];
    for(int i = n/2+1; i < n; i++){
        ans1 -= v[i] * 2;
    }

    long long ans2 = 0;
    for(int i = 0; i < (n-1)/2; i++){
        ans2 += v[i]*2;
    }
    if(n%2 == 0) ans2 += v[(n-1)/2];
    else ans2 -= v[(n-1)/2];
    ans2 -= v[(n-1)/2+1];
    for(int i = (n-1)/2+2; i < n; i++){
        ans2 -= v[i] * 2;
    }

    cout << max(ans1, ans2) << endl;
    return 0;
}