#include <bits/stdc++.h>
#define ll  long long int
#define ull unsigned long long int 
#define pb  push_back
#define mp  make_pair
#define pii pair<int, int>
using namespace std;

const ll mod = 1e9+7;
const int N = 1e4;
const int K = 1e2;
string s;
int d;
ll dp[N+1][K+1] = {0};
bool check[N+1][K+1] = {0};

ll dp_recurse(int k, int remainder){
	//cout << k << " " << remainder << endl;
	if(k==0){
		if(remainder == 0){
			return 1;
		}
		return 0;
	}

	if(check[k][remainder] == 1){
		return dp[k][remainder];
	}

	ll sum = 0;
	for(int i=0;i<10;i++){
		sum = (sum + dp_recurse(k-1, (remainder - i%d + d)%d ) )%mod;
	}

	dp[k][remainder] = sum;
	check[k][remainder] = 1;
	return sum;
}

void solve(){
    //solve here//
	cin >> s;
	cin >> d;

	int remainder = 0;
	ll ans = 0;
	int len = s.size();
	for(int i=0;i<len-1;i++){
		int num = int(s[i]-'0');

		for(int j=0;j<num;j++){
			ans = (ans + dp_recurse(len-i-1, (-remainder - j%d + 3*d)%d ))%mod;
			//cout << ans << " " << len-i-1 << " " << j << endl;
		}

		remainder = (remainder + num)%d;
	}

	int num = int(s[len-1]-'0');
	for(int i=0;i<=num;i++){
		if((remainder+i)%d==0){
			ans = (ans+1)%mod;
		}
	}

	ans = (ans-1+mod)%mod;
	//cout << d << " " << s << endl;
	cout << ans << endl;
}


int main(){
    ll t=1;
    //cin >> t;
    while(t--){
        solve();
    }
}

