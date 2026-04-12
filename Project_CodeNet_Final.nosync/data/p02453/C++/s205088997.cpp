#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(){
    int n; cin >> n;
    int a[n];
    for(int i = 0;i < n; ++i) cin >> a[i];
    int q; cin >> q;
    while(q--){
        int k;cin >> k;
        int left = 0;
        int right = n;
        int middle = (right + left)/2;
        while(left < right){
            if(a[middle] >= k){
                right = middle;
            } else {
                left = middle + 1;
            }
            middle = (left + right)/2;
        }
        cout << middle << endl;
    }
}

int main(){
    solve();
    return 0;
}
