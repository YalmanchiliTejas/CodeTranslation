#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

typedef long long int ll;

#define FOR(i,n,m) for(ll i=(ll)(m);i<(ll)(n);++i)
#define REP(i,n) FOR(i,n,0)
#define IREP(i,n) for(ll i=(ll)(n);i>=0;--i)

const ll MOD = 1000000007;

using namespace std;

int A[200005];
int B[200005];

int main()
{
	int N;
	cin >> N;

	REP(i, N)
	{
		cin >> A[i];
		B[i] = A[i];
	}
	sort(A, A + N);
	int c1 = A[N / 2 - 1];
	int c2 = A[N / 2];
	REP(i, N)
	{
		if (B[i] <= c1)
		{
			cout << c2 << endl;
		}
		else
		{
			cout << c1 << endl;
		}
	}
	return 0;
}