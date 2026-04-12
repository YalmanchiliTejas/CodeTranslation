
#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void Get_Val(int &Ret)
{
	Ret = 0;
	char ch;
	while (ch = getchar(), ch > '9' || ch < '0')
		;
	do
	{
		(Ret *= 10) += ch - '0';
	}
	while (ch = getchar(), ch >= '0' && ch <= '9');
}

const int Max_N(200050);
typedef long long int LL;

struct node
{
	int X, Y;
};
int N;
LL Ans(0X3F3F3F3F3F3F3F3FLL);
node V[Max_N];

void init()
{
	Get_Val(N);
	for (int i = 1;i <= N;++i)
	{
		Get_Val(V[i].X), Get_Val(V[i].Y);
		if (V[i].X > V[i].Y)
			swap(V[i].X, V[i].Y);
	}
}

void Task1()
{
	int RMax(V[1].X), RMin(V[1].X), BMax(V[1].Y), BMin(V[1].Y);
	for (int i = 2;i <= N;++i)
	{
		RMax = max(RMax, V[i].X), RMin = min(RMin, V[i].X);
		BMax = max(BMax, V[i].Y), BMin = min(BMin, V[i].Y);
	}
	Ans = min(Ans, (RMax - RMin + 0LL) * (BMax - BMin + 0LL));
}

struct qwq
{
	qwq(const int &_p = 0, const int &_v = 0) : p(_p), v(_v) {}
	int p, v;
};

inline bool operator<(const qwq &a, const qwq &b)
{
	return a.v == b.v ? a.p < b.p : a.v < b.v;
}

int Tot, All[Max_N << 1];
set<qwq> R;
set<int> L;
map< int, vector<qwq> > M;
set<qwq>::iterator Rit;
set<int>::iterator Lit;
inline int qR()
{
	if (R.size())
	{
		Rit = R.end();
		return (--Rit) -> v;
	}
	else
		return -0X3F3F3F3F;
}

inline int qL()
{
	if (L.size())
	{
		Lit = L.end();
		return *(--Lit);
	}
	else
		return -0X3F3F3F3F;
}

void Task2()
{
	int AllMax(max(V[1].X, V[1].Y)), AllMin(min(V[1].X, V[1].Y)), YMin(V[1].Y);
	for (int i = 2;i <= N;++i)
	{
		AllMax = max(AllMax, max(V[i].X, V[i].Y));
		AllMin = min(AllMin, min(V[i].X, V[i].Y));
		YMin = min(YMin, V[i].Y);
	}
	for (int i = 1;i <= N;++i)
		All[++Tot] = V[i].X, All[++Tot] = V[i].Y, M[V[i].X].push_back(qwq(i, V[i].X)), R.insert(qwq(i, V[i].X));
	sort(All + 1, All + 1 + Tot);
	for (int i = 1;i <= Tot && All[i] <= YMin;++i)
	{
		Ans = min(Ans, (AllMax - AllMin + 0LL) * (max(qR(), qL()) - All[i] + 0LL));
		if (i <= Tot && All[i + 1] != All[i])
		{
			vector<qwq> &vec = M[All[i]];
			for (int j = 0;j != vec.size();++j)
				R.erase(vec[j]), L.insert(V[vec[j].p].Y);
		}
	}
}

int main()
{
	init();
	Task1();
	Task2();
	printf("%lld", Ans);
	return 0;
}