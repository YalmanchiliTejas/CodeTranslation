#include <bits/stdc++.h>
#define MAXN 100100
#define pii pair<int, int>
#define pb push_back
typedef long long ll;

using namespace std;

ll n, k;
ll ans = 0;
//12012
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n >> k;
    for(ll b = k + 1; b <= n; b++){
    	ans += (n / b) * (b - k);
    	int t = n % b;
    	if(t == 0) continue;
    	ans += max(t - k + 1, 0LL);
    	if(k == 0) ans--;
    	//cout << ans << endl;
    }
    cout << ans;
}