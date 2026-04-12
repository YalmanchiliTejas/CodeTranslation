#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

ll n,k;
ll ans=0;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
	
	cin >> n >> k;
	
	for(int b=k+1;b<=n;b++){
		ll q=n/b;
		
		ans+=q*(b-k);
		
		if(n%b>=k){
			ans+=(n%b-k+1);
		}
	}
	
	if(k==0) ans-=n;
	
	cout << ans << endl;
    return 0;
}