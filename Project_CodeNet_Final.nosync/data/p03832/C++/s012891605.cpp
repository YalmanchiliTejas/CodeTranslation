//Author : pakhandi
//
using namespace std;

#include <bits/stdc++.h>

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; i++)
#define rev(i,a,b) for(i=a; i>=b; i--)

#define si(n) scanf("%d", &n)
#define sll(l) scanf("%lld",&l)

#define debug(x) cout<<"\n#("<<x<<")#\n"
#define nline printf("\n")

#define mem(a,i) memset(a,i,sizeof(a))

#define MOD 1000000007
#define ll long long int
#define u64 unsigned long long int

#define PB push_back
#define SZ size
#define MP make_pair

#define IGNORE cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

const ll INF = (1LL << 58);
const bool DEBUG = 0;

long long power(long long _n,long long _k, long long _mod)
{
	long long r=1;
	while(_k) {
		if(_k&1) {
			r = ((r * _n) % _mod);
		}
		_n = ((_n * _n) % _mod);
		_k>>=1;
	}
	return (r % _mod);
}

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
	mem(dp, -1);
	mem(dp2, -1);

	fl(i,0,1001)
	{
		fl(j,0,1001)
		{
			if(i * j < 1003)
				getWays(i, j);
		}
	}

	si(N);	si(A);	si(B);	si(C);	si(D);

	printf("%d\n", rec(N, A));

	return 0;
}
/*
	Powered by Buggy Plugin
*/
