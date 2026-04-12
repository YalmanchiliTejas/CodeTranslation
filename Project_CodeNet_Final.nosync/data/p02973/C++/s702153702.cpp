#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // sort
#include <map> // pair
#include <queue>
#include<iomanip>
#include <cmath>
#include <set>

#define ABS(x) ((x)>0?(x):-(x))
#define MIN(x,y) ((x)>(y)?(y):(x))

using namespace std;
typedef long long ll;

ll newton(long long int a, long long int  b)
{
	if(a==b)
		return a;
	while(a != 0 && b != 0)
	{
		if(a > b)
		{
			b += a;
			a = b-a;
			b -= a;
		}
		b %= a;
	}
	return a;
}

struct UnionFind {
	vector<int> p;
	UnionFind(int N):p(N)
	{
		for(int i=0; i< N; i++)
		{
			p[i] = i;
		}
	}
	int root(int x)
	{
		if(p[x] == x)
			return x;
		return p[x] = root(p[x]);
	}
	void unite(int x, int y)
	{
		int rx = root(x);
		int ry = root(y);
		if(rx == ry) return;
		p[rx] = ry;
	}
	bool issame(int x, int y)
	{
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
};

//大きな数に対する割り算をするとき、MODを指定することで掛け算の値に変換できる

ll div2mul_calc(ll a, ll b, ll m)
{
	if (b == 0) {
        return 1;
    } else if (b % 2 == 0) {
        ll d = div2mul_calc(a, b / 2, m);
        return (d * d) % m;
    } else {
        return (a * div2mul_calc(a, b - 1, m)) % m;
    }
}
ll div2mul(ll n, ll mod)
{
	return div2mul_calc(n, mod-2, mod);
}

ll twoRow(ll a, ll b, ll mod)
{
	ll ret = 1;
	for(ll i = 1 ;i <= a+b;++i)
	{
		ret *= i;
		ret %= mod;
	}
	for(ll i = 1 ;i <= a;++i)
	{
		ret *= div2mul(i,mod);
		ret %= mod;
	}
	for(ll i = 1 ;i <= b;++i)
	{
		ret *= div2mul(i,mod);
		ret %= mod;
	}
	return ret;
}



int main()
{
	multiset<int> s;
	int N;
	int size = 0;
	cin >> N;
	int j;
	for(int i = 0;i < N; ++i)
	{
		cin >> j;
		if(size)
		{
			auto itr = s.insert(j);
			auto beg = s.begin();
			if(itr == beg || j == *beg)
			{
				size ++;
			}
			else
			{
				itr = s.lower_bound(j);
				--itr;
				s.erase(itr);
			}
		}
		else
		{
			s.insert(j);
			size = 1;
		}
	}
	cout << size << endl;
	return 0;
}


















