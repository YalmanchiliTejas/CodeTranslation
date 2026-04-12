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

ll func(ll W, ll H)
{
	ll ans = 0;
	for(ll i=0; i < W; ++i)
	{
		if(i > 0)
		{
			ans += i*(i+1)/2;
		}
		if (i < W - 1)
		{
			ans += (W-i)*(W-i-1)/2;
		}
	}
	ans /= (ll)2;
	ans *= H;
	ans %= (ll)1000000007;
	ans *= H;
	ans %= (ll)1000000007;
	return ans;
}

int main()
{
	ll N,M,K;
	ll i,j,k,l;
	cin >> N >> M >> K;
	ll ans = func(N,M)+func(M,N);
	ans %= (ll)1000000007;
	ll S = (ll)N*M;
	/*
	for(i=1;i<=K;++i)
	{
		ans*=(S-i);
		ans/=i;
		ans %= 1000000007;
	}
	*/
	ll div = 1;
	ll mul = S-2;
	for(i=1; i <= K-2; ++i)
	{
		ans *= (S-i-1);
		ans %= (unsigned long long)1000000007;
		ans *= div2mul(i,(unsigned long long)1000000007);
		ans %= (unsigned long long)1000000007;
	}

	cout << ans << endl;
	return 0;
}


































