/*
 * File: CountTheRegions.cpp
 * Author: Magica
 * Date: 2014.08.26
 ****************************************/
#include <bits/stdc++.h>
using namespace std;
#define Multicase for (int TestCase = 1, TestCaseSum = xint(); TestCase <= TestCaseSum; ++TestCase)
#define __cin__ { cin.sync_with_stdio(0); cin.tie(0); }
#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }
#define mp make_pair
#define pb push_back
#define init(range, val) memset(range, val, sizeof(range))
typedef pair<int, int> pii;
typedef long long ll;
char buf;
inline char xchar() { while (buf = getchar(), isspace(buf)); return buf; }
inline int xint() { while (buf = getchar(), buf < '0' || buf > '9'); int x = buf - '0'; for (; buf = getchar(), buf >= '0' && buf <= '9'; x = x * 10 + buf - '0'); return x; }
inline ll xll() { while (buf = getchar(), buf < '0' || buf > '9'); ll x = buf - '0'; for (; buf = getchar(), buf >= '0' && buf <= '9'; x = x * 10 + buf - '0'); return x; }
inline string xstring() { while (buf = getchar(), buf == ' ' || buf == '\n'); string x = ""; for (x += buf; buf = getchar(), buf != ' ' && buf != '\n' && buf != '\r'; x += buf); return x; }
inline string xline() { while (buf = getchar(), buf == ' ' || buf == '\n'); string x = ""; for (x += buf; buf = getchar(), buf != '\n' && buf != '\r'; x += buf); return x; }
struct Point
{
    int x, y;
};
bool XCompare(Point A, Point B)
{
    return A.x < B.x;
}
bool YCompare(Point A, Point B)
{
    return A.y < B.y;
}
map<int, int> X, Y;
int L[55], T[55], R[55], B[55], Col[305][305];
Point All[105];
bool Map[305][305];
const int dx[] = {-1, 0, 0, 1},
          dy[] = {0, -1, 1, 0};
inline bool in(int x, int y)
{
    return x > 0 && x <= 302 && y > 0 && y <= 302;
}
void FloodFill(int x, int y, int c)
{
    int d, cx, cy;
    Col[x][y] = c;
    for (d = 0; d < 4; ++d) {
        cx = x + dx[d];
        cy = y + dy[d];
        if (in(cx, cy) && !Col[cx][cy] && !Map[cx][cy])
            FloodFill(cx, cy, c);
    }
}
int main()
{
    int i, j, n, Xt, Yt, Total, Ans;
    while ((n = xint()) != 0) {
        init(Map, 0);
        init(Col, 0);
        X.clear();
        Y.clear();
        Xt = Yt = Total = Ans = 0;
        for (i = 0; i < n; ++i) {
            L[i] = xint();
            T[i] = xint();
            R[i] = xint();
            B[i] = xint();
            ++Total;
            All[Total].x = L[i]; All[Total].y = T[i];
            ++Total;
            All[Total].x = R[i]; All[Total].y = B[i];
        }
        sort(All + 1, All + Total + 1, XCompare);
        for (i = 1; i <= Total; ++i)
            if (X.find(All[i].x) == X.end()) {
                Xt += 2;
                X[All[i].x] = Xt;
            }
        sort(All + 1, All + Total + 1, YCompare);
        for (i = 1; i <= Total; ++i)
            if (Y.find(All[i].y) == Y.end()) {
                Yt += 2;
                Y[All[i].y] = Yt;
            }
        for (i = 0; i < n; ++i) {
            L[i] = X[L[i]];
            R[i] = X[R[i]];
            T[i] = Y[T[i]];
            B[i] = Y[B[i]];
            for (j = L[i]; j <= R[i]; ++j)
                Map[T[i]][j] = Map[B[i]][j] = 1;
            for (j = B[i]; j <= T[i]; ++j)
                Map[j][L[i]] = Map[j][R[i]] = 1;
        }
        for (i = 1; i <= 302; ++i)
            for (j = 1; j <= 302; ++j)
                if (!Col[i][j] && !Map[i][j])
                    FloodFill(i, j, ++Ans);
        printf("%d\n", Ans);
    }
    return 0;
}