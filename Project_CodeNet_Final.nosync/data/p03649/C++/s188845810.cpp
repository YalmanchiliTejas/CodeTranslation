#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define debug(x) cerr << #x << " = " << (x) << endl;
template<typename T>
ostream& operator<<(ostream& o, vector<T>& v) {
    for (auto& x : v) o << x << ' ';
    return o;
}

int n; 
ll apply(vector<ll> &arr){
    vector<ll> tmp(n);
    for (int i = 0; i < n; i++){
        tmp[i] = arr[i] / n;
        arr[i] %= n;
    }
    ll tot = accumulate(tmp.begin(), tmp.end(), 0LL);
    for (int i = 0; i < n; i++){
        arr[i] += (tot - tmp[i]);
    }
    return tot;
}

int main(){
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    ll res = 0;
    ll cur = 0;
    while ((cur = apply(arr))){
        res += cur;
    }
    cout << res << endl;
}
