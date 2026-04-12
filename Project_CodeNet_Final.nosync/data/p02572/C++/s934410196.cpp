#include<iostream>

using namespace std;

int main()
{
	long long N;
	long long *A;

	cin >> N;
	A = new long long[N];

	long long ans = 0;

	for(int i=0;i<N;i++)
	{
		cin >> A[i];
	}

	long long sum = 0;

	for(int i=N-2;i>=0;i--)
	{
		long long sub = A[i] * ((sum + A[i+1])%1000000007);
		ans += sub%1000000007;
		sum += A[i+1];
	}

	cout << ans%1000000007 << endl;

	return 0;
}