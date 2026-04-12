#include<iostream>
using namespace std;
typedef long long ll;
ll A[100005];
ll sum[100005];
bool vis[100005];

int main()
{
	long long N;
	cin >> N;
	ll X,M;
	cin >> X >> M;
	if(N == 1 || M == 1)
	{
		cout << X << endl;
		return 0;
	}
	A[1] = X;
	sum[1] = X;
	vis[A[1]] = true;
	ll ans = 0;
	for(int i = 2; i <= N; i++)
	{
		A[i] = A[i-1] * A[i-1] %M;
		sum[i] = A[i] + sum[i-1];
		if(i == N)
		{
			cout << sum[i] << endl;
			return 0;
		}
		if(A[i] == 0)
		{
			if(X>i)
			cout << sum[i] << endl;
			else cout << sum[X] << endl;
			return 0;
		}
		if(vis[A[i]] == true)
		{
			int j = 1; 
			for(;A[j] != A[i];j++);
			ans = ans + sum[i-1];
			long long n = N-i+1;
			ans = ans + n/(i-j) * (sum[i-1]-sum[j-1]);
			ans = ans + sum[j-1+(n%(i-j))] - sum[j-1];
			cout << ans << endl;
			return 0;
			
		}
		vis[A[i]] = true;
	}
}