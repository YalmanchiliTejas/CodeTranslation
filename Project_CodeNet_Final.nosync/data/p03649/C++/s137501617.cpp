#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#define llint long long 
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[55];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint ans = 0;
	while(1){
		llint mx = -1, mx_i;
		for(int i = 1; i <= n; i++){
			if(mx < a[i]){
				mx = a[i];
				mx_i = i;
			}
		}
		if(mx < n) break;
		
		llint q = a[mx_i] / n;
		a[mx_i] %= n;
		for(int i = 1; i <= n; i++){
			if(i == mx_i) continue;
			a[i] += q;
		}
		ans += q;
	}
	cout << ans << endl;
	
	return 0;
}