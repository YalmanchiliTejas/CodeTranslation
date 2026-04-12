#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

template<class T> bool umin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool umax(T &a, T b) { return a < b ? (a = b, true) : false; }

using namespace std;

unordered_map<uint32_t, uint32_t> memo;
constexpr uint32_t M = 1e9 + 7;
string K;
uint32_t D;

uint32_t calcMask(uint32_t pos, uint32_t rem, bool checkK)
{
	return pos + (rem << 16) + (checkK ? 1 << 30 : 0);
}

uint32_t calc(uint32_t pos, uint32_t rem, bool checkK)
{
	if (pos == K.size())
	{
		if (rem == 0)
			return 1;
		return 0;
	}
	uint32_t h = calcMask(pos, rem, checkK);
	
	if (memo.count(h))
		return memo[h];

	uint32_t KA = K[pos] - '0';
	uint32_t res = 0;

	for (uint32_t i = 0; i < 10; ++i)
	{
		if (checkK && i == KA)
		{
			res = res + calc(pos + 1, (rem + i)%D, true);
			if (res >= M)
				res -= M;
			break;
		}
		res = res + calc(pos + 1, (rem + i) % D, false);
		if (res >= M)
			res -= M;
	}
	memo[h] = res;
	return res;
}

int main(int argc, char** argv) 
{
#ifdef HOME
	if(IsDebuggerPresent())
	{
		freopen("../in.txt", "rb", stdin);
		freopen("../out.txt", "wb", stdout);
	}
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;
	
	cin >> K >> D;
	uint32_t r = calc(0, 0, true);
	cout << (r > 0? r-1 : M-1) << endl;
	return 0;
}
