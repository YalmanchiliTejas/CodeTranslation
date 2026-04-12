/*
このコード、と～おれ!
Be accepted!
∧＿∧　
（｡･ω･｡)つ━☆・*。
⊂　　 ノ 　　　・゜+.
　しーＪ　　　°。+ *´¨)
 　　　　　　　　　.· ´¸.·*´¨) ¸.·*¨)
		  　　　　　　　　　　(¸.·´ (¸.·'* ☆
					*/

#pragma GCC optimize("Ofast")
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i <= (n); ++i)
#define repr(i, n) for(int i = n; i >= 0; --i)
#define reprm(i, n) for(int i = n - 1; i >= 0; --i)
#define printynl(a) printf(a ? "yes\n" : "no\n")
#define printyn(a) printf(a ? "Yes\n" : "No\n")
#define printYN(a) printf(a ? "YES\n" : "NO\n")
#define printfin(a) printf(a ? "possible\n" : "inposible\n")
#define all(x) (x).begin(), (x).end()
using ll = long long;

const int INF = 2147483647;
//const ll LINF = ll();今度書く

//マクロとかここまで

#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

int main() {
	
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printYN((100 * a + 10 * b + c) % 4 == 0);

	return 0;
}
