#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n,k,sum = 0;
	cin >> n >> k;
	for(LL i = k + 1LL;i <= n;i++){
		for(LL j = 1LL;j <= n;j++){
			if(j * i > n){
				if((j - 1LL) * i == n) break;
				LL p = 0;
				if(k == 0) p = 1LL;
				LL ans = max(n - (j * i - (i - k - p)) + 1LL,0LL);
				sum += ans;
				break;
			}
			else sum += i - k;
		}
	}
	cout << sum << endl;
}