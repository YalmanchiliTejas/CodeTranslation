#include <iostream>
#define llint long long

using namespace std;

llint n;
llint l, r;
llint a[55];

int main(void)
{
	while(1){
		cin >> n >> l >> r;
		if(n == 0 && l == 0 && r == 0) break;
		
		llint ans = 0;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = l; i <= r; i++){
			for(int j = 1; j <= n; j++){
				if(i%a[j] == 0){
					if(j%2) ans++;
					goto end;
				}
			}
			if(n%2==0) ans++;
			end:;
		}
		cout << ans << endl;
	}
	
	return 0;
}
