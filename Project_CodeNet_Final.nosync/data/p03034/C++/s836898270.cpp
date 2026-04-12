#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[100005];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	llint ans = 0;
	for(int i = 1; i < n-1; i++){
		llint sum = 0;
		if(i >= n-1-i) continue;
		for(int j = i; j <= n-1; j+=i){
			if((n-1-j)%i == 0 && j >= (n-1-j)) break;
			if((n-1-j)<=i) break;
			sum += a[j] + a[n-1-j];
			ans = max(ans, sum);
			//cout << i << " " << j << " " << ans << endl;
		}
	}
	cout << ans << endl;
	
	return 0;
}