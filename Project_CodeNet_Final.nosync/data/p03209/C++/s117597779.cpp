#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void fill_all(T& a, const T& b)
{
	a = b;
}
template<typename T, size_t N, typename U>
void fill_all(T(& a)[N], const U& b)
{
	for (auto& i : a)
	{
		fill_all(i, b);
	}
}


int64_t dp[51];
int64_t func(int i)
{
	if (i == 0) {
		return 1;
	}
	if (dp[i] != -1) {
		return dp[i]
			;
	}
	auto a = func(i - 1);
	return dp[i] = 1 + a * 2;
}
int64_t numdp[51];
int64_t numfunc(int i)
{
	if (i == 0) {
		return 1;
	}
	if (numdp[i] != -1) {
		return numdp[i]
			;
	}
	auto a = numfunc(i - 1);
	return numdp[i] = 3 + a * 2;
}
int64_t func2(int i, int64_t x)
{
	if (x == 0) {
		return 0;
	}
	if (i == 0) {
		return 1;
	}
	auto num2 = numfunc(i);
	if (num2 == x) {
		return func(i);
	}

	int64_t res = 0;
	auto num = numfunc(i - 1);
	if (num+2 <= x) {
		res += func(i - 1) + 1 + func2(i - 1, x - (num + 2));
	}
	else if (num + 1 == x) {
		res += func(i - 1);
	}
	else {
		res += func2(i - 1, x-1);
	}
	return res;
}
int main() {
	fill_all(dp, (int64_t)-1);
	fill_all(numdp, (int64_t)-1);
	int64_t N, X;
	cin >> N >> X;
	cout << func2(N, X) << endl;
}

#if 0
int P, R, Q;
int r_num[300];
std::vector<int> resolved[300][101];

int main()
{
	cin >> P >> R >> Q;
	for (int i = 0; i < R; i++)
	{
		cin >> r_num[i];
	}



}
#endif