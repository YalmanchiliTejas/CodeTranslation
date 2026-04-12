# define _CRT_SECURE_NO_WARNINGS 1
# include <iostream>
# include <numeric>
# include <string>
# include <bitset>
# include <vector>
# include <algorithm>
# include <cstdlib>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iomanip>
# include <queue>
# include <sstream>
# include <climits>
# include <cmath>
# include <list>
# include <functional>
# include <string>
# include <ctime>
# include <set>
# include <map>
# include <stack>
using namespace std;
//# define M_PI 3.141592
# define INF ((int)(1<<30))
# define FOR(i,n) for(int i=0;i<(int)n;i++)
# define FORI(i,k,n) for(int i=k;i<(int)n;i++)
# define toRad 2.0*M_PI/360.0
# define inin(x) int x;cin>>x;
# define all(x) x.begin(),x.end()
# define debug(x) cout<<#x<<" :"<<x<<endl;
# define rep(i,n) for(int i=0;i<(int)n;i++)
# define EPS 1e-12
# define CHECK(i,a) FOR(i,a.size())cout<<#a<<"["<<i<<"] : "<<a[i]<<endl; 

class Point
{
public:
	double x, y;

	Point(double x = 0, double y = 0) :x(x), y(y) {}


	Point operator + (Point p) { return Point(x + p.x, y + p.y); }
	Point operator - (Point p) { return Point(x - p.x, y - p.y); }
	Point operator * (double k) { return Point(x * k, y * k); }
	Point operator / (double k) { return Point(x / k, y / k); }
	bool operator < (const Point &p)const { return x != p.x ? x < p.x : y < p.y; }
	bool operator ==(const Point &p)const { return fabs(x - p.x) < EPS&&fabs(y - p.y) < EPS; }

	double abs() { return sqrt(norm()); }
	double norm() { return x*x + y*y; }
};
typedef Point Vector;
struct Segment
{
	Point p1, p2;
};
typedef Segment Line;
class Circle
{
public:
	Point c;
	double r;
	Circle(Point c = Point(), double r = 0.0) :c(c), r(r) {}
};

double dot(Vector a, Vector b) { return a.x*b.x + a.y*b.y; }//??????
double cross(Vector a, Vector b) { return a.x*b.y - a.y*b.x; }//??????
bool isOrthogonal(Vector a, Vector b) { return fabs(dot(a, b)) < EPS; }//??´??????
bool isOrthogonal(Point a1, Point a2, Point b1, Point b2) { return isOrthogonal(a1 - a2, b1 - b2); }
bool isOrthogonal(Line l1, Line l2) { return fabs(dot(l1.p2 - l1.p1, l2.p2 - l2.p1)) < EPS; }
bool isParallel(Vector a, Vector b) { return fabs(cross(a, b)) < EPS; }//?????????
bool isParallel(Point a1, Point a2, Point b1, Point b2) { return isParallel(a1 - a2, b1 - b2); }
bool isParallel(Line l1, Line l2) { return fabs(cross(l1.p2 - l1.p1, l2.p2 - l2.p1)) < EPS; }
Point project(Line s, Point p)
{
	Vector base = s.p2 - s.p1;
	double r = dot(p - s.p1, base) / base.norm();
	return s.p1 + base*r;
}


int dx[5] = { 0,-1,0,1,0 }, dy[5] = { 1,0,0,0,-1 };
bool check(int a[12][12])
{
	int t = 0;
	for (int i = 1; i <= 10; i++)for (int j = 1; j <= 10; j++)t += a[i][j];
	return t == 0;
}
void paint(int f[12][12], int x, int y)
{
	for (int k = 0; k < 5; k++)
	{
		f[x + dx[k]][y + dy[k]]++;
		f[x + dx[k]][y + dy[k]] %= 2;
	}
}
int main()
{
	int n; cin >> n;
	while (n--)
	{
		int a[12][12] = {};
		bool ans[12][12] = {};
		for (int i = 1; i <= 10; i++)
		{
			for (int j = 1; j <= 10; j++)
			{
				cin >> a[i][j];
			}
		}
		for (int c = 0; c < 1024; c++)
		{
			int f[12][12];
			memset(ans, 0, sizeof ans);
			for (int i = 0; i < 12; i++)for (int j = 0; j < 12; j++)f[i][j] = a[i][j];
			bitset<10> b(c);
			for (int i = 1; i <= 10; i++)
			{
				ans[1][i] = b[i - 1];
				if (b[i - 1])
				{
					paint(f, 1, i);
				}
			}
			for (int i = 2; i <= 10; i++)
			{
				for (int j = 1; j <= 10; j++)
				{
					if (f[i - 1][j])
					{
						paint(f, i, j);
						ans[i][j] = true;
					}
				}
			}
			if (check(f))break;
		}
		for (int i = 1; i <= 10; i++)
		{
			for (int j = 1; j <= 10; j++)
			{
				cout << ans[i][j];
				if (j != 10)cout << " ";
			}
			cout << endl;
		}
	}
}