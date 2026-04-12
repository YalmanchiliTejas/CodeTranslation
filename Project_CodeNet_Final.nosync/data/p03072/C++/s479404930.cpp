#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define debug(x) cout << "[debug] " << #x << ": " << x << endl
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;

int main() {
    int n; cin >> n;
    int ans = 1;
    vector<int> h;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        h.push_back(x);
    }
    int y = h[0];
    for(int i = 1; i < n; ++i){
        if(h[i] >= y){
            ans++;
            y = h[i];
        }
    }
    cout << ans << endl;
	return 0;
}