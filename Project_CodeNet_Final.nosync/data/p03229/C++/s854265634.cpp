#include <bits/stdc++.h>
using namespace std;

const int INF = 1145141919;
const long long INFL = 1LL<<60;

template<class T>
inline bool chmin(T& a, T b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}

template<class T>
inline bool chmax(T& a, T b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}

int main()
{
	long long int N;
	cin >> N;
	long long int A[110000];
	for (long long int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	sort(A, A + N);
	long long int ans = 0;
	long long int ans2 = 0;
	long long int ansA[110000];
	long long int ansB[110000];
	for (long long int i = 0; i < (N/2)*2; ++i)
	{
		ansA[i] = (i % 2 == 0?A[N-1-i/2]:A[i/2]);
		ansB[i] = (i % 2 == 1?A[N-1-i/2]:A[i/2]);
	}
	for (long long int i = 0; i < (N/2)*2-1; ++i)
	{
		ans += abs(ansA[i]-ansA[i+1]);
		ans2 += abs(ansB[i]-ansB[i+1]);
	}
	if(N % 2 != 0)
	{
		// cout << max(abs(ansA[0] - A[N/2]), abs(ansA[N-1] - A[N/2])) << endl;
		ans += max(abs(ansA[0] - A[N/2]), abs(ansA[N-2] - A[N/2]));
		ans2 += max(abs(ansB[0] - A[N/2]), abs(ansB[N-2] - A[N/2]));
	}
	else
	{
		ans -= abs(ansA[N-2]-ansA[N-1]);
		ans += max(abs(ansA[N-2]-ansA[N-1]),abs(ansA[0]-ansA[N-1]));
		ans2 -= abs(ansB[N-2]-ansB[N-1]);
		ans2 += max(abs(ansB[N-2]-ansB[N-1]),abs(ansB[0]-ansB[N-1]));
	}
	cout << max(ans, ans2) << endl;
}