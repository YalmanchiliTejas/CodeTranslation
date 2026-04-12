#include <bits/stdc++.h>

using namespace std;

inline long long ceil(long long x, long long y)
{
	return (x+y-1)/y;
}

bool process(vector<long long> a, int n, long long T)
{
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		long long y1 = ceil(a[i]+T-n+1,n+1);
		long long y2 = (a[i]+T)/(n+1);
		if (y1 != y2) return false;
		sum += y1;
	}
	return sum == T;
}

int main()
{
	int n; cin >> n; 
	vector<long long> a(n);
	long long S = 0;
	for (auto & x : a) { cin >> x; S += x; }
	long long H = S; long long L = max(0ll, S - (n*(n+1)));
    
	for (long long T = L; T <= H; T++)
		if (process(a,n,T))
		{
			cout << T << endl;
			break;
		}
	return 0;
}