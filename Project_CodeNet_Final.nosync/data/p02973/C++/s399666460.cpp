#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> b;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    b.push_back(-a[0]);
    for(int i=1;i<n;i++){
        auto iter = upper_bound(b.begin(), b.end(), -a[i]);
        // cout << *iter << endl;
        if(iter == b.end()){
            b.push_back(-a[i]);
            continue;
        }
        *(iter) = -a[i];
    }
    /*
    for(ll bi: b){
        cout << bi << endl;
    }
    */
    cout << b.size() << endl;
}