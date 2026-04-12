#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <cstring>
#include <cmath>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <bitset>
#include <random>
#include <iterator>
#include <cassert>
#include <cstdint>
#include <string>
#pragma comment(linker, "/STACK:10000000000")

using namespace std;

#define LLD "%I64d"

void print_str(const char* s)
{
	while (*s != 0)
	{
		putchar(*s);
		s++;
	}
}

template<typename T> void scan(T &t)
{
	cin >> t;
}

template<> void scan<int>(int &t)
{
	scanf("%d", &t);
}

template<> void scan<long long>(long long &t)
{
	scanf(LLD, &t);
}

template<> void scan<string>(string &t)
{
	cin >> t;
}

template<> void scan<char*>(char* &t)
{
	scanf("%s", t);
}

template<> void scan<char>(char &t)
{
	t = getchar();
	while (t <= 32)
		t = getchar();
}

template<typename T> void scan(vector<T> &t)
{
	for (int i = 0; i < t.size(); i++)
	{
		scan(t[i]);
	}
}


template<typename T, typename... Ts> void scan(T& t, Ts&... ts)
{
	scan(t);
	scan(ts...);
}

template<typename T> void print(T t)
{
	cout << t;
}

template<> void print<string>(string s)
{
	print_str(s.c_str());
}

template<> void print<int>(int t)
{
	printf("%d", t);
}

template<> void print<long long>(long long t)
{
	printf(LLD, t);
}

template<> void print<char>(char t)
{
	putchar(t);
}

template<> void print<const char*>(const char* t)
{
	print_str(t);
}

template<typename T, typename V> void print(pair<T, V> t)
{
	printf("(");
	print(t.first);
	printf(", ");
	print(t.second);
	printf(")");
}

template<typename T, typename... Ts> void print(T t, Ts... ts)
{
	print(t);
	print(ts...);
}

#define TASK "nocross"
#define X first
#define Y second

const int INF = 1e9;
const long long LINF = 3e18;
const int maxN = 1e5 + 100;
const int maxM = 58;
const int K = 10000;
const int SIZE = (1 << 18);
const int mb = 30;
const long long MOD = 1e9 + 7;
const long long P = 127;
const double EPS = 1e-8;

mt19937_64 random_generator;

long long random(long long l, long long r)
{
	uniform_int_distribution<long long> dist(l, r);
	long long res = dist(random_generator);
	return res;
}

namespace solution
{
}

namespace bruteforce
{
}

void init(bool testing = false)
{

}

void gen(int seed)
{
}

int a[maxN];

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
#endif

	int n;
	string s;
	cin >> n >> s;

	for (int f = 0; f < 2; f++)
	{
		for (int m = 0; m < 2; m++)
		{
			for (int l = 0; l < 2; l++)
			{
				a[n - 1] = f;
				a[0] = m;
				a[1] = l;
				if (a[0] == 0 && s[0] == 'o' && a[n - 1] != a[1] || a[0] == 0 && s[0] == 'x' && a[n - 1] == a[1])
				{
					continue;
				}
				if (a[0] == 1 && s[0] == 'o' && a[n - 1] == a[1] || a[0] == 1 && s[0] == 'x' && a[n - 1] != a[1])
				{
					continue;
				}
				for (int i = 1; i < n - 1; i++)
				{
					if (a[i] == 0)
					{
						if (s[i] == 'o')
						{
							a[i + 1] = a[i - 1];
						}
						else
						{
							a[i + 1] = 1 - a[i - 1];
						}
					}
					else
					{
						if (s[i] == 'o')
						{
							a[i + 1] = 1 - a[i - 1];
						}
						else
						{
							a[i + 1] = a[i - 1];
						}
					}
				}
				string t(n, '0');
				for (int i = 0; i < n; i++)
				{
					if (a[i] == 0)
					{
						if (a[(n + i - 1) % n] == a[(i + 1) % n])
							t[i] = 'o';
						else
							t[i] = 'x';
					}
					else
					{
						if (a[(n + i - 1) % n] == a[(i + 1) % n])
							t[i] = 'x';
						else
							t[i] = 'o';
					}
				}
				if (t == s)
				{
					for (int i = 0; i < n; i++)
					{
						if (a[i] == 0)
							cout << 'S';
						else
							cout << 'W';
					}
					return 0;
				}
			}
		}
	}

	cout << -1;

	return 0;
}