//Christmas

#include <cstdio>

template<long long I, long long A>
struct layers
{
	long long values[I + 1];
	constexpr layers() : values()
	{
		values[0] = 1;
		for (int i = 1; i <= I; ++i)
		{
			values[i] = 2 * values[i - 1] + A;
		}
	}
};

constexpr auto ls = layers<50, 3>();
constexpr auto ps = layers<50, 1>();

long long patties(long long n, long long x)
{
	if (n == 0)
	{
		return 1;
	}
	if (x == 1)
	{
		return 0;
	}
	else if (x <= ls.values[n - 1] + 1)
	{
		return patties(n - 1, x - 1);
	}
	else if (x == ls.values[n - 1] + 2)
	{
		return 1 + ps.values[n - 1];
	}
	else if (x <= 2 * ls.values[n - 1] + 2)
	{
		return 1 + ps.values[n - 1] + patties(n - 1, x - (2 + ls.values[n - 1]));
	}
	else
	{
		return 1 + 2 * ps.values[n - 1];
	}
}

int main()
{
	long long n, x;
	scanf("%lld %lld", &n, &x);
	printf("%lld\n", patties(n, x));
	return 0;
}