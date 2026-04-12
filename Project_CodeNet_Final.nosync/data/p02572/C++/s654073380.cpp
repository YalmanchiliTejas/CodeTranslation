#include <bits/stdc++.h>
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define all(var) var.begin(), var.end()
#define input freopen("input", "r", stdin)
#define output freopen("output", "w", stdout)
#define Fast ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL)
typedef unsigned long long ll;
using namespace std;

int dr[] = {0, 0, -1, +1, -1, -1, +1, +1};
int dc[] = {-1, +1, 0, 0, -1, +1, -1, +1};

const ll mod = 1e9+7;

int main(){
    int n; cin >> n;
    ll arr[n];
    ll pref[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        pref[i] = arr[i];
    }
    for(int i = 1; i < n; i++){
        pref[i] += pref[i-1];
    }
    ll ans = 0;
    for(int i = 0; i < n-1; i++){
        ans += ( arr[i] * ((pref[n-1]-pref[i])%mod) )%mod;
    }
    cout << ans%mod << endl;
}

