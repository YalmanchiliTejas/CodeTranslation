/*
¼ÙÉèS[1] = R¡£ÄÇÃ´ÏÔÈ»£¬»·ÉÏ²»»á³öÏÖÁ½¸öÁ¬ÐøµÄ±ß¶¼ÊÇB£¬·ñÔòÔÚËüÃÇ½»µã´¦µÚÒ»²½ÍùÁ½±ß×ß¶¼²»ºÏ·¨
ÌØÅÐµôSÖÐÈ«ÊÇRµÄÇé¿ö£¬¿¼ÂÇÒ»°ãÇé¿ö 
Ê×ÏÈ°ÑËùÓÐÊÇBµÄÎ»ÖÃ¶Ï¿ª£¬ÄÇÃ´¾ÍÐÎ³ÉÁËÈô¸É¸öRµÄÁ¬Ðø¶Î¡£¿ÉÒÔ·¢ÏÖÕâÃ´Ò»¸öÐÔÖÊ£ºÃ¿¸öÁ¬Ðø¶ÎµÄ³¤¶È¾ùÎªÆæÊý
Ö¤Ã÷¿¼ÂÇ·´Ö¤¡£¼ÙÉèÓÐÒ»¸öÅ¼ÊýµÄ¶Î£¬¿¼ÂÇ¶þ·ÖÍ¼¿ÉÒÔ·¢ÏÖ£¬ÄÇÃ´ÓÐµÄµã×ßµ½ÕâÒ»¶ÎµÄ¶Ëµã¾àÀëÓÀÔ¶ÊÇÅ¼Êý¡¢ÓÐµÄµã×ßµ½ÕâÒ»¶ÎµÄ¶Ëµã¾àÀëÓÀÔ¶ÊÇÆæÊý£¬ÒòÎª¶ËµãÍ¬É«
¶øSµÄµÚÒ»¶ÎÁ¬ÐøR³¤¶ÈÊÇ¹Ì¶¨µÄ£¬²»ÄÜÍ¬Ê±ÎªÅ¼Êý»òÆæÊý£¬Ã¬¶Ü¡£ËùÒÔ¿ÉÒÔµÃµ½½áÂÛ
Í¬Ê±£¬SÖÐÃ¿¸öRµÄÁ¬Ðø¶Î¶¼»á¶Ô»·ÉÏÃ¿¸öRµÄÁ¬Ðø¶ÎÓÐ¸öÉÏ½çµÄÏÞÖÆ 
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int Max_NM(200050);
const int MOD(1000000000 + 7);
typedef long long int LL;

int N, M, L, F[Max_NM], Pre[Max_NM][2], Ans;
char S[Max_NM];

constexpr int Add(int a, int b)
{
	return a + b >= MOD ? a + b - MOD : a + b;
}

constexpr int Sub(int a, int b)
{
	return a - b < 0 ? a - b + MOD : a - b;
}

constexpr int Mult(int a, int b)
{
	return a * 1LL * b % MOD;
}

inline void upd(int &a, int b)
{
	a = Add(a, b);
}

void dp(bool have)
{
	F[1] = 1, Pre[1][1 & 1] = 1;
	for (int i = 2, j;i <= N;++i)
	{
		Pre[i][0] = Pre[i - 1][0], Pre[i][1] = Pre[i - 1][1];
		upd(Pre[i][i & 1], F[i - 2]);
		//jµ½iÊÇR£¬i - j + 1 <= L   =>   j >= i - L + 1
		//i - j + 1ÊÇÆæÊý£¬i - jÊÇÅ¼Êý£¬iºÍjÆæÅ¼ÐÔÏàµÈ
		j = max(1, i - L + 1);
		if (j <= i)
		{
			F[i] = Sub(Pre[i][i & 1], Pre[j - 1][i & 1]);
			if (have)
				upd(F[i], Sub(Pre[i][(i & 1) ^ 1], Pre[j - 1][(i & 1) ^ 1]));
		}
	}
	
}

int main()
{
	scanf("%d%d", &N, &M);
	scanf("%s", S + 1);
	bool haveB = false;
	if (S[1] == 'B')
		for (int i = 1;i <= M;++i)
			S[i] = 'R' + 'B' - S[i];
	for (int i = 1;i <= M;++i)
		haveB |= (S[i] == 'B');
	L = N;
	for (int i = 1, length = 0, stop = 0;i <= M;++i)
		if (S[i] == 'B')
			length = 0, stop = 1;
		else
		{
			++length;
			if (i + 1 <= M && S[i + 1] == 'B')
				if (stop == 0)
					if (length & 1)
						L = min(L, length);
					else
						L = min(L, length + 1);
				else
					if (length & 1)
						L = min(L, length);
		}
	dp(!haveB);
	upd(Ans, F[N - 1]);//edge(1, 2) = B
	for (int x = 1, val;x <= L && x < N;++x)//edge(1, 2) = R
	{
		if (haveB && ((x & 1) == 0))
			continue;
		if (x + 1 == N)
			val = 1;
		else
			val = F[N - x - 2];
		upd(Ans, Mult(x, val));
	}
	if (haveB == false)
		upd(Ans, 1);
	printf("%d", Ans);
	return 0;
}