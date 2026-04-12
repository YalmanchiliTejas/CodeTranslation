#include<algorithm>
#include<cmath>
#include<cstdio>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()


ll combination(int n, int r)
{
	if (n - r < r) r = n - r;
	if (r == 0) return 1;
	if (r == 1) return n;

	vector<int> numerator(r, 0);
	vector<int> denominator(r, 0);

	rep(k, r)
	{
		numerator[k] = n - r + k + 1;
		denominator[k] = k + 1;
	}

	reple(p, 2, r)
	{
		int pivot = denominator[p - 1];
		if (pivot > 1)
		{
			int offset = (n - r) % p;
			for (int k = p - 1; k < r; k += p)
			{
				numerator[k - offset] /= pivot;
				denominator[k] /= pivot;
			}
		}
	}

	ll result = 1;
	rep(k, r)
	{
		if (numerator[k] > 1)
		{
			result *= numerator[k];
			result %= mod;
		}
	}

	return result;
}


ll calc(int n, int m, int k)
{
	//任意に2点とるとき、その2点間の距離は、その2点を含むk個をmn個から選ぶすべてのパターンに含まれる。
	ll c = combination(n * m - 2, k - 2);

	ll sum = 0;
	reple(d, 1, n - 1)
	{
		//x座標の差がdであるすべての場合について足し合わせ
		sum += c * (((ll)n - d) % mod) * (m % mod) * (m % mod) * (d % mod);
		sum %= mod;
	}

	return sum;
}


int main()
{	
	//解答方針
	//任意の2マスを固定して距離を計算。その後、全パターンの和の中にその2マスの距離が何回出現するか計算する。
	//※パターンを決めて距離を計算し、全パターンについて和をとるのが問題文を素直に読んだ時の解答方法だが、
	//その方法では全パターンを網羅できない（mn_C_kものパターンを網羅する必要があり、時間内に解答できない）
	//イメージとしては、和の順番を入れ替えることで、mn_C_k回のループをなくして、mn_C_kと距離の積に置きなおした感じ

	int n, m, k;
	cin >> n >> m >> k;

	//距離の計算は、xとyが完全に独立しているため、xの和とyの和を別々に計算できる。
	ll distX = calc(n, m, k);
	ll distY = calc(m, n, k);

	cout << (distX + distY) % mod << endl;

	return 0;
}