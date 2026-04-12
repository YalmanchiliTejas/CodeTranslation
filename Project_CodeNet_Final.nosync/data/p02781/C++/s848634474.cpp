#include <iostream>
#include <string>

using namespace std;

long long comb(int n, int r)
{
	long long c = 1;
	for(int i = n; i > n - r ; --i)
		c *= i;
	for(int i = 1; i <= r; ++i)
		c /= i;
	return c;
}

long long fact9(int n)
{
	long long fact = 1;
	while(n--)
		fact *= 9;
	return fact;
}

long long AEZ9(int digits, int k)
{
	if(k > digits) return 0;
	return comb(digits, k) * fact9(k);
}

long long AEZ(string S, int k)
{
	if(k == 0) return 1;
	
	long long s = S[0] - '0';
	int len = S.length();
	if(len == 1)
		if(k == 1) return s;
		else return 0;
	
	if(s == 0)
		return AEZ(S.substr(1), k);
	
	return AEZ(S.substr(1), k - 1) + AEZ9(len - 1, k - 1) * (s - 1) + AEZ9(len - 1, k);
}

int main()
{
	string S;
	int k;
	
	cin >> S >> k;
	
	cout << AEZ(S, k);
}
