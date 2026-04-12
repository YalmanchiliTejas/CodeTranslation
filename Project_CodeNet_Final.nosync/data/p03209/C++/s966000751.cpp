#include<iostream>
#include <algorithm>
#include<string>
#include <bitset>
#include <vector>
#include <functional>
#include <climits>
#include <iomanip>
#include <utility>
#include <stack>
#include <queue>
#include <math.h>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <numeric>
using namespace std;
using ll = long long;

typedef pair <int, int> pii;

int main()
{

	ll a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, ans = 0;
	string s, t;



	ll x, n;
	cin >> n;
	cin >> x;
	ll pb = 0;
	b = 1;
	pb = 1;
	for (int i = 0; i < n; i++)
	{
		b = b * 2 + 1;
		pb = pb * 2 + 3;
	}

	while (x >= 1)
	{
		
		if (pb <= 5)
		{
			if (x==1)
			{
				
			}
			else if(x==5)
			{
				ans += 3;
			}
			else
			{
				ans += x-1;
			}
			break;
		}
		else if (x == pb)
		{
			ans += b;
			break;
		}
		else if (x == 1 + (pb - 3) / 2)
		{
			ans += (b - 1) / 2;
			break;
		}
		else if (x == 2 + (pb - 3) / 2)
		{
			ans += (b - 1) / 2 + 1;
			break;
		}
		else if (x <= 1 + (pb - 3) / 2)
		{
			pb = (pb - 3) / 2;
			b = (b - 1) / 2;
			x -= 1;
		}
		else
		{
			x -= (pb - 3) / 2 + 2;
			ans += (b - 1) / 2 + 1;
			pb = (pb - 3) / 2;
			b = (b - 1) / 2;
		}
	}

	cout << ans << endl;

	//cout << ans << endl;
	//cout <<  << endl;

	////std::cout << std::fixed;
	//cout << std::setprecision(20) << << endl;
	//cout << d+1 << endl;
	//cout << "" << endl;

	return 0;
}
//char型の文字数字は、-'0'で数値に変換できる
//accumulate(x, x + a, 0);//int型までの配列の合計
//memcpy(x, visited, sizeof(ll)*n);
//void kansuu(ll num, ll visited[10]) {}
//kansuu(1, zz);
//cout << setprecision(15) << v << endl;
//cout << char(z - 'a');
//log10(i) + 1 //10進数の桁数を取得

//int temp;
//for (int i = 0; i < n - 1; i++) {
//	for (int j = n - 1; j > i; j--) {
//		if (w[j - 1] < w[j]) {  /* 前の要素の方が大きかったら */
//			temp = w[j];        /* 交換する */
//			w[j] = w[j - 1];
//			w[j - 1] = temp;
//		}
//	}
//}

//最小公倍数
//ll x = a * b;
//ll tmp;
///* 自然数 a > b を確認・入替 */
//if (a<b) {
//	tmp = a;
//	a = b;
//	b = tmp;
//}
///* ユークリッドの互除法 */
//ll r = a % b;
//while (r != 0) {
//	a = b;
//	b = r;
//	r = a % b;
//}
//a = x / b;//答え