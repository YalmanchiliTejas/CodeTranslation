#include <bits/stdc++.h>

#define ll long long
#define MAXN 3010
using namespace std;

const ll mod = 998244353LL;
int A[MAXN];
int N, S;


ll dp2[MAXN];

int main()
{
	cin>>N>>S;
	ll ans = 0;
	for(int i = 1; i <= N; ++i)
		cin>>A[i];
	memset(dp2, 0, sizeof(dp2));
	dp2[A[N]] = 1;
	ans = ans + dp2[S] * N;
	for(int i = N - 1; i >= 1; --i)
	{
			if(A[i] < S)
				ans = (ans + dp2[S-A[i]] * i) % mod;
			if(A[i] == S)
				ans = (ans + (N-i+1)*i) % mod;
			for(int j = S; j > A[i]; --j)
			{
					dp2[j] += dp2[j-A[i]];
					dp2[j] %= mod;
			}
			
			dp2[A[i]] += (N-i+1);
	}
	cout<<ans<<endl;
}
