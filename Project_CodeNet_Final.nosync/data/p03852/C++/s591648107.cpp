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

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = n; i >= 0; --i)
#define printynl(a) printf(a ? "yes\n" : "no\n")
#define printyn(a) printf(a ? "Yes\n" : "No\n")
#define printYN(a) printf(a ? "YES\n" : "NO\n")
#define printfin(a) printf(a ? "possible\n" : "inposible\n")
#define all(x) (x).begin(), (x).end()
using ll = long long;

//マクロとかここまで

#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

int main() {
	
	char c;
	scanf("%c", &c);
	if( c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')printf("vowel\n");
	else printf("consonant\n");
	return 0;
}
	    