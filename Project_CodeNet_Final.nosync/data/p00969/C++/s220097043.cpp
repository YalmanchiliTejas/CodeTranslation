#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
using ll = long long;

int a[5010];
int dp[5010][5010];
map<int, int> mp;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
    int n; cin >> n;
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    int ans=2;
    sort(a, a+n);
    for(int i=0; i<n; ++i){
        mp[a[i]]=i;
    }
    
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            dp[i][j] = max(dp[i][j], 2);
            
            ans = max(ans, dp[i][j]);
            int k = a[j]+a[j]-a[i];
            
            if(mp.find(k)!=mp.end()){
                int idx = mp[k];
                dp[j][idx] = max(dp[j][idx], dp[i][j] + 1);
            }
        }
    }
    cout << ans << endl;
    
	return 0;

}
