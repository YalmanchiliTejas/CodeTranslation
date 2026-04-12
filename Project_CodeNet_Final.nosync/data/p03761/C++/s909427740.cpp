#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(), v.end()
#define mem(arr) memset(arr, 0, sizeof(arr))
#define ff first
#define ss second
#define int long long int
const int MOD = 1e9 + 7;
const int INF = 1e18;
const int N = 1e6 + 1;
vector<int> g[N];
vector<int> vis(N);
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> cnt(n, vector<int> (26));
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(char &c : s){
            cnt[i][c - 'a']++;
        }
    }
    vector<int> mn(26, INF);
    string ans;
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < n; j++){
            mn[i] = min(mn[i], cnt[j][i]);
        }
        for(int j = 0; j < mn[i]; j++){
            char c = i + 'a';
            ans += c;
        }
    }
    cout << ans << '\n';
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    while(tc--){
        solve();
    }
}