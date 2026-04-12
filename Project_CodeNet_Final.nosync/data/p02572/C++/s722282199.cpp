#include<iostream>

using namespace std;

const int N = 2e5 + 10;
long long int a[N];
int n;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	long long int sum = 0;
	
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
			
		sum += a[i];
		sum %= 1000000007;
	}
	
	long long ans = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		sum -= a[i];
		while(sum < 0) sum += 1000000007;
		
		ans += a[i] * sum;
		ans %= 1000000007;
	}
	
	cout << ans << endl;
	
	return 0;
}