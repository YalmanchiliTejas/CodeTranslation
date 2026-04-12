using namespace std;
 
#include <bits/stdc++.h>

const int MOD = 1000000007;

inline int add(int _a, int _b)
{
	_a += _b;
	if(_a >= MOD)
	{
		_a -= MOD;
	}
	return _a;
}
 
inline int mul(int _a, int _b)
{
	return (long long) _a * _b % MOD;
}
 
long long power(long long base, long long expo, long long _mod)
{
	if(base == 1)	return 1;
	if(expo == 0)	return 1;
	if(expo == 1)	return base;

	int ret = power(base, expo / 2, _mod);
	ret = mul(ret, ret);
	if(expo % 2 == 1)
	{
		ret = mul(ret,base);
	}

	return ret;
}
 
int N, A, B, C, D;
int dp[1003][1003];
int dp2[1003][1003];
int comb[2003][2003];
 
void pre()
{
	for(int i = 0; i < 2003; i++)
	{
		comb[i][0] = 1;
		for(int j = 1; j <= i; j++)
		{
			comb[i][j] = add(comb[i - 1][j], comb[i - 1][j - 1]);
		}
	}
}
 
int getWays(int groups, int groupSize)
{
	if(groups == 0)
		return 1;
 
	int &ret = dp2[groups][groupSize];
	if(ret != -1)
		return ret;
	ret = mul(comb[groups * groupSize][groupSize], power(groups, MOD - 2, MOD));
	ret = mul(getWays(groups - 1, groupSize), ret);
	return ret;
}
 
int rec(int people, int groupSize)
{
	if(groupSize > B)
	{
		if(people == 0)	return 1;
		return 0;
	}
 
	int &ret = dp[people][groupSize];
	if(ret != -1)
		return ret;
	// cerr << people << " " << groupSize << "\n";
	ret = rec(people, groupSize + 1);
 
	for(int i = C; i <= D; i++)
	{
		int peopleIncluded = i * groupSize;
		if(peopleIncluded > people)
			break;
		int thisAns = rec(people - peopleIncluded, groupSize + 1);
		thisAns = mul(thisAns, comb[people][peopleIncluded]);
		thisAns = mul(thisAns, getWays(i, groupSize));
		ret = add(ret, thisAns);
	}
 
	return ret;
}
 
 
int main()
{
	int i, j;
 
	pre();
	
	memset(dp, -1, sizeof(dp));
	memset(dp2, -1, sizeof(dp2));
 
	for(i = 0; i < 1001; i++)
	{
		for(j = 0; j < 1001; j++)
		{
			if(i * j < 1003)
				getWays(i, j);
		}
	}
 
	cin >> N >> A >> B >> C >> D;
 
	printf("%d\n", rec(N, A));
 
	return 0;
}