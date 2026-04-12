#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1e9 + 7/*998244353*/;
const ll INF = 1LL << 60;
ll mod_pow(ll, ll, ll); ll mod_fact(ll, ll); ll mod_inv(ll, ll); ll gcd(ll, ll); ll lcm(ll, ll);
//
int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {cin >> a[i]; b[i] = a[i];}
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        int num = b[i];
        int left = -1;
        int right = n - 1;
        while(right - left != 1){
            int middle = (left + right) / 2;
            if(a[middle] >= num) right = middle;
            else left = middle;
        }
        //cout << right << "\n";
        if(right < n / 2) cout << a[n / 2] << "\n";
        else cout << a[n / 2 - 1] << "\n";
    }
}