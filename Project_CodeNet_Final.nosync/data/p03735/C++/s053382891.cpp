#include <cstdio>
#include <algorithm>
struct point
{
	int x, y;
}
p[200002];
int N, L = 1 << 30, R = -1 << 30;
long long diff()
{
	int WL = L, WR = R;
	for (int i = 1; i <= N; i++)
	{
		if (p[i].x > p[i].y)
			std::swap(p[i].x, p[i].y);
		WL = std::max(WL, p[i].x);
		WR = std::min(WR, p[i].y);
	}
	return (long long)(WL - L) * (R - WR);
}
int same()
{
	for (int i = 1; i <= N; i++)
		if (p[i].x > p[i].y)
			std::swap(p[i].x, p[i].y);
	std::sort(p + 1, p + N + 1, [] (const point &a, const point &b) { return a.x < b.x; });
	static int xmin[200002], xmax[200002], ymin[200002], ymax[200002];
	xmin[N + 1] = ymin[0] = 1 << 30;
	xmax[N + 1] = ymax[0] = -1 << 30;
	for (int i = N; i; i--)
	{
		xmin[i] = std::min(xmin[i + 1], p[i].x);
		xmax[i] = std::max(xmax[i + 1], p[i].x);
	}
	for (int i = 1; i <= N; i++)
	{
		ymin[i] = std::min(ymin[i - 1], p[i].y);
		ymax[i] = std::max(ymax[i - 1], p[i].y);
	}
	int O = 1 << 30;
	for (int i = 0; i <= N; i++)
		O = std::min(O, std::max(xmax[i + 1], ymax[i]) - std::min(xmin[i + 1], ymin[i]));
	return O;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d%d", &p[i].x, &p[i].y);
		L = std::min(L, p[i].x);
		R = std::max(R, p[i].x);
		L = std::min(L, p[i].y);
		R = std::max(R, p[i].y);
	}
	printf("%lld\n", std::min(diff(), (long long)(R - L) * same()));
	return 0;
}
