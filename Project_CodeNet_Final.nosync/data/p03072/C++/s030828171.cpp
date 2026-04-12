#include<iostream>
#include<cstdlib>
#include<stack>
#include<queue>
using namespace std;

int max(int x, int y);
int min(int x, int y);
int gcd(int x, int y);	/*最大公約数*/
int lcm(int x, int y);	/*最小公倍数*/
void swap(int* x, int* y);	/*値の交換*/
void downsort(int* a, int n);	/*降順ソート*/
void upsort(int* a, int n);	/*昇順ソート*/

typedef stack<int> IntStack;
typedef queue<int> IntQueue;

/*ここまでテンプレ*/

/*ここからmain関数*/

int main()
{
	int n, h[20];
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> h[i];

	int ans = 1;
	for (int i = 1;i < n;i++)
	{
		int judge = 0;
		for (int j = 0;j < i;j++)
			if (h[j] > h[i])
				judge = 1;
		if (judge == 0)
			ans++;
	}

	cout << ans;

	return 0;
}

/*2数の大きい方を返す*/
int max(int x, int y)
{
	int max;

	if (x < y)
		max = y;
	else
		max = x;

	return max;
}

/*2数の小さい方を返す*/
int min(int x, int y)
{
	int min;

	if (x < y)
		min = x;
	else
		min = y;

	return min;
}

/*2数の最大公約数を返す*/
int gcd(int x, int y)
{
	int m;
	int gcd = 1;

	m = min(x, y);

	for (int i = 1;i <= m; i++)
	{
		if (x%i == 0 && y%i == 0)
			gcd = i;
	}

	return gcd;
}

/*2数の最小公倍数を返す*/
int lcm(int x, int y)
{
	int m;

	for (int i = 1;i <= y;i++)
	{
		if ((x*i) % y == 0) {
			m = x * i;
			break;
		}
	}

	return m;
}

/*2数の値を交換する*/
void swap(int* px, int* py)
{
	int temp;

	temp = *px;
	*px = *py;
	*py = temp;
}

/*クイックソートによる降順並べ替え*/
void downsort(int* a, int n)
{
	//初期設定
	int l = 0, r = n - 1;

	// ピボットの決定
	int piv = *a;

	//ピボットより大を左に、ピボット以下を右に
	while (l < r)
	{
		if (*(a + l) > piv)
			l++;
		else if (*(a + r) <= piv)
			r--;
		else
			swap(a + l, a + r);
	}

	//再帰処理
	if (n == 2)
		return;
	else if (l == 1 || l == 0)
		downsort(a + 1, n - 1);
	else if (r == n - 1)
		downsort(a, n - 1);
	else
	{
		downsort(a, l);
		downsort(a + l, n - l);
	}
}

/*クイックソートによる昇順ソート*/
void upsort(int* a, int n)
{
	downsort(a, n);

	for (int i = 0;i < n / 2;i++)
		swap(a[i], a[n - 1 - i]);
}