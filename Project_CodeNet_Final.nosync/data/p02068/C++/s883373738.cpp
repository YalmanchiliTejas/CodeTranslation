#include <string>
#include <iostream>
#include <map>
#define llint long long

using namespace std;

llint n;
llint a[1005];
map<llint, llint> mp;

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j*j <= a[i]; j++){
			if(a[i] % j == 0){
				mp[j] += a[i];
				if(j*j != a[i]) mp[a[i]/j] += a[i];
			}
		}
	}
	llint ans = 0;
	for(auto it = mp.begin(); it != mp.end(); it++){
		if(it->first == 1) continue;
		//cout << it->first << " " << it->second << endl;
		ans = max(ans, it->second);
	}
	cout << ans << endl;
	
	return 0;
}
