#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b)-1; i >= (a); i--)
#define ITER(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL) INF;

const int MAX = 10;

string A[MAX];

void NO()
{
	cout<<"Impossible"<<endl;
	exit(0);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin>>n>>m;

	int cnt = 0;

	FOR (i, 0, n)
	{
		cin>>A[i];
		FOR (j, 0, m)
		{
			if (A[i][j] == '#') cnt++;
		}
	}

	if (cnt != (n + m - 1))
	{
		NO();
	}

	int x = 0, y = 0;
	FOR (it, 1, cnt)
	{
		if (x == n-1)
		{
			if (A[x][y+1] != '#') NO();
			y++;
			continue;
		}
		if (y == m-1)
		{
			if (A[x+1][y] != '#') NO();
		}

		if (A[x+1][y] == '#' && A[x][y+1] == '#') NO();
		if (A[x+1][y] != '#' && A[x][y+1] != '#') NO();
		if (A[x+1][y] == '#') x++;
		else y++;
	}

	cout<<"Possible"<<endl;

}


