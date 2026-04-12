#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<int(n); i++)
#define ALL(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;

const ll mod = 1e9 + 7;

long long gcd(ll x, ll y){
	if(x > y) swap(x, y);
	while(x != 0){
		y %= x;
		swap(x, y);
	}
	return y;
}


ll mpow(ll x, ll r){
	if(r == 1) return x;
	if(r % 2 == 1) return x * mpow(x, r-1) % mod;
	else{
		ll aa = mpow(x, r/2);
		return aa*aa%mod;
	}
}

ll N;
ll A[200010];
ll ans[200010];

ll solve(int num){
	
}

int main(){
	cin >> N;
	rep(i, N) cin >> A[i];
	if(N%2 == 0){
		ll cnt = 0, ans;
		rep(i, (N/2)+1){
			if(i==0){
				rep(j, N/2){
					cnt += A[2*j+1];
				}
				ans = cnt;
			}else{
				cnt -= A[2*i-1];
				cnt += A[2*i-2];
				if(cnt > ans) ans = cnt;
			}
		}
		cout << ans << endl;
	}else{
		ll dp[N+1];
		ll sum[N];
		for(int i=N-1; i>=0; i--){
			if(i%2==1) continue;
			if(i==N-1) sum[i] = A[i];
			else{
				sum[i] = A[i] + sum[i+2];
			}
		}
		rep(i, N+1){
			if(i<=1) dp[i] = 0;
			else{
				if(i%2==0){
					dp[i] = max(A[N-i]+dp[i-2], sum[N-i+1]);
				}else{
					dp[i] = max(sum[N-i+2], max(A[N-i]+dp[i-2], A[N-i+1]+dp[i-3]));
				}
			}
		}
		cout << dp[N] << endl;
	}
	return 0;
}