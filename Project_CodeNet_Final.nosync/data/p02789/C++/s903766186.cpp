#include<iostream>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<math.h>
#include<bitset>
#include<iomanip>
#include<numeric>
#include<list>
using namespace std;

typedef stack<int> IntStack;
typedef queue<int> IntQueue;

const double pi = 3.141592653589793;


//最大公約数
template<class T> T gcd(T a, T b)
{
	while (true)
	{
		T r;
		if (a%b == 0) return b;
		else
		{
			r = a % b;
			a = b;
			b = r;
		}
	}
}
//最小公倍数
template<class T> T lcm(T a, T b)
{
	return a / gcd(a, b)*b;
}
//文字0~9をint型0~9に変換
int char_to_int(char c)
{
	if (c == '0') return 0;
	if (c == '1') return 1;
	if (c == '2') return 2;
	if (c == '3') return 3;
	if (c == '4') return 4;
	if (c == '5') return 5;
	if (c == '6') return 6;
	if (c == '7') return 7;
	if (c == '8') return 8;
	if (c == '9') return 9;
	else return -1;
}
//int型0~9を文字0~9に変換
char int_to_char(int c) {
	if (c == 0) return '0';
	if (c == 1) return '1';
	if (c == 2) return '2';
	if (c == 3) return '3';
	if (c == 4) return '4';
	if (c == 5) return '5';
	if (c == 6) return '6';
	if (c == 7) return '7';
	if (c == 8) return '8';
	if (c == 9) return '9';
	else return'x';
}
//a^b mod MODを計算
long long int ModPower(long long int a, long long int b, long long int MOD)
{
	if (b == 0) return 1;
	else if (b % 2 == 0)
	{
		long long int d = ModPower(a, b / 2, MOD);
		return (d*d) % MOD;
	}
	else
	{
		return (a*ModPower(a, b - 1, MOD)) % MOD;
	}
}
//nCr mod MODを計算
long long int ModCombi(long long int n, long long int r, long long int MOD)
{
	if (n == 0 || r == 0) return 1;

	long long int Kn = 1, Kr = 1, Knr = 1;

	long long int temp = 1;
	for (long long int i = 1; i <= n; i++)
	{
		temp *= i;
		temp %= MOD;
		if (i == n) Kn = temp;
		if (i == r) Kr = temp;
		if (i == n - r) Knr = temp;
	}

	long long int x = ModPower(Kr, MOD - 2, MOD);
	long long int y = ModPower(Knr, MOD - 2, MOD);

	long long int ans;
	ans = Kn * x;
	ans %= MOD;
	ans *= y;
	ans %= MOD;

	return ans;
}
//int型10進数をord桁のstring型2進数に変換する
string binary(int x, int ord)
{
	int y;
	string ans = "";
	for (int i = 0; i < ord; i++)
	{
		y = x / (int)pow(2, ord - 1 - i);
		y %= 2;
		if (y == 0) ans += "0";
		else ans += "1";
	}

	return ans;
}
//ord桁のstring型2進数をint型10進数に変換する
int rep_binary(string x, int ord)
{
	int res = 0;
	for (int i = 0; i < ord; i++)
	{
		if (x[i] == '1') res += (int)pow(2, ord - 1 - i);
	}
	return res;
}
//xとyのビットごとの排他的論理和
template<class T> T XOR(T x, T y)
{
	T n = 0;
	while (max(x, y) > pow(2, n)) n++;
	T ans=0;
	for (int i = 0; i <= n; i++)
	{
		T x1 = (x % (T)pow(2, i + 1)) / (T)pow(2, i);
		T y1 = (y % (T)pow(2, i + 1)) / (T)pow(2, i);
		if (x1 != y1) ans += (T)pow(2, i);
	}
	return ans;
}

/*ここまでテンプレ*//*ここまでテンプレ*//*ここまでテンプレ*//*ここまでテンプレ*/



int main()
{
	int N, M;
	cin >> N >> M;
	if (N == M)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}