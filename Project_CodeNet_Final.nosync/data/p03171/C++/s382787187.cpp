#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n, x;
vector <ll> a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> x;
        a.push_back(x);
        int sz = a.size();
        while(sz >= 3 && a[sz - 2] >= a[sz - 1] && a[sz - 2] >= a[sz - 3]){
            ll c = a[sz - 3] - a[sz - 2] + a[sz - 1];
            a.pop_back();
            a.pop_back();
            a.pop_back();
            a.push_back(c);
            sz -= 2;
        }
    }
    int l = 0, r = a.size() - 1;
    ll ans = 0;
    int z = 1;
    while(l <= r){
        if(a[l] >= a[r]){
            ans += a[l] * z;
            l++;
        }
        else{
            ans += a[r] * z;
            r--;
        }
        z *= -1;
    }
    cout << ans << endl;
}
