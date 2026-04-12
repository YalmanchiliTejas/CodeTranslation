#include<bits/stdc++.h>
using namespace std;

//#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define LL long long

const int mod = 998244353;
const int MX = 3005;

LL n, s;
LL inp[MX];
LL dp[MX][MX];
LL pre[MX][MX];

int main() {
	cin >> n >> s;
	for(int i=1;i<=n;i++) {
		cin >> inp[i];
	}

	for(int i=1;i<=n;i++) {
		dp[i][inp[i]] = i;
	}

	for(int i=1;i<=n;i++) {
		for(int k=1;k<=s;k++) {
			pre[i][k] = (pre[i-1][k] + dp[i][k])%mod;
		}
	}

	for(int i=1;i<=n;i++) {
		for(int k=1;k<=s;k++) {
			if(inp[i] < k) {
				dp[i][k] = (dp[i][k] + pre[i-1][k-inp[i]])%mod;
			}
			pre[i][k] = (pre[i-1][k] + dp[i][k])%mod;
		}
	}

	LL ans = 0;
	for(int i=1;i<=n;i++) {
		ans = (ans + (dp[i][s] * (n - i + 1))%mod)%mod;
	}

	cout << ans << endl;

	return 0;
}
