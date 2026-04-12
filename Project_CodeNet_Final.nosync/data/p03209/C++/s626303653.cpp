
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#ifndef U_L_LONG
typedef unsigned long long U_L_LONG;
#endif
#ifndef L_LONG
typedef long long L_LONG;
#endif


static void ABC115D_Christmas();

#if 1
int main()
{
	ABC115D_Christmas();

	fflush(stdout);
	return 0;
}
#endif


class ABC115D_Burger
{
public:
	L_LONG _bun = 0;
	L_LONG _patty = 0;
	L_LONG _total = 0;
	L_LONG _center = 0;
};


static L_LONG ABC115D_getPatty(ABC115D_Burger* bgr, int lv, L_LONG eatCount)
{
	L_LONG eatenPatty = 0;

	if (lv == 0) {
		return ((eatCount > 0) ? 1 : 0);
	}
	
	if (eatCount == bgr[lv]._center) {
		eatenPatty = ((bgr[lv]._patty - 1) / 2) + 1;
	}
	else {
		if (eatCount > bgr[lv]._center) {
			//	半分までの分は計算を済ませておく
			eatenPatty = ((bgr[lv]._patty - 1) / 2) + 1;
			eatCount -= ((bgr[lv]._total - 1) / 2) + 1;
		}
		else {
			eatCount--;	//	バン1枚分
		}
		if (eatCount > 0) {
			eatenPatty += ABC115D_getPatty(bgr, lv - 1, eatCount);
		}
	}

	return eatenPatty;
}

static void ABC115D_Christmas()
{
	int N;
	L_LONG X;

	scanf(" %d %lld", &N, &X);

	ABC115D_Burger bgr[51];

	bgr[0]._patty = 1;
	for (int lv = 1; lv <= N; lv++) {
		bgr[lv]._bun = (bgr[lv - 1]._bun * 2) + 2;
		bgr[lv]._patty = (bgr[lv - 1]._patty * 2) + 1;
		bgr[lv]._total = bgr[lv]._patty + bgr[lv]._bun;
		bgr[lv]._center = ((bgr[lv]._total - 1) / 2) + 1;
	}

	printf("%lld\n", ABC115D_getPatty(bgr, N, X));
}
