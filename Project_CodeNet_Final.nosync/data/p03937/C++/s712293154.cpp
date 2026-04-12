#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<functional>
#include<stack>
#include<queue>
#include <iomanip>
#include<map>
#include<limits>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<utility>
#include<complex>
#include<cstdlib>
#include<set>
#include<cctype>

#define DBG cerr << '!' << endl;
#define REP(i,n) for(int (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(int (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(int (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int i = 0;i < (n);i++)cerr << v[i] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)

using namespace std;

typedef long long ll;
typedef vector<int> iv;
typedef vector<iv> iiv;
typedef vector<string> sv;

char mp[100][100];

int main()
{
	int h,w;cin>>h>>w;
	int num = 0;
	REP(i,100)REP(j,100)mp[i][j] = '.';
	REP(i,h)REP(j,w){cin >> mp[i][j];if(mp[i][j] == '#')num++;}
	
	int sx = 0,sy = 0;
	int tmp = 1;
	
	while(1)
	{
		if(sx == w-1&&sy == h-1)
		{
			if(tmp == num)
			{
				cout << "Possible" << endl;
				return 0;
			}
			else
			{
				cout << "Impossible" << endl;
				return 0;
			}
		}
		int a = sx,b = sy,cou = 0;
		if(mp[b][a+1] == '#')
		{
			cou++;sx++;
		}
		if(mp[b+1][a] == '#')
		{
			cou++;sy++;
		}
		if(cou != 1)
		{
			cout << "Impossible" << endl;
			return 0;
		}
		tmp++;
	}
	
	return 0;
}
