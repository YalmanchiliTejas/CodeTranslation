#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<functional>
#include<stack>
#include<queue>
#include<iomanip>
#include<map>
#include<limits>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<deque>
#include<utility>
#include<complex>
#include<cstdlib>
#include<set>
#include<cctype>

using namespace std;

#define DBG cerr << '!' << endl;
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(ll (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(ll (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(10)

typedef long long ll;
typedef vector<int> iv;
typedef vector<iv> iiv;
typedef vector<string> sv;

ll mp[11][11];
ll dist[222][222];
ll mi[22][22];

int main()
{
	int a,b;cin >> a >> b;
	REP(i,22)REP(j,22)mi[i][j] = 10000;
	
	REP(i,a)
	{
		REP(j,b)
		{
			cin >> mp[i][j];
		}
	}
	
	REP(i,101)
	{
		REP(j,101)
		{
			ll tmp = 0;
			REP(x,a)
			{
				REP(y,b)
				{
					tmp = max(tmp,mp[x][y]-(i*(x+1))-(j*(y+1)));
				}
			}
			
			REP(x,a)
			{
				REP(y,b)
				{
					mi[x][y] = min(mi[x][y],tmp+(i*(x+1))+(j*(y+1)));
				}
			}
			
			dist[i][j] = tmp;
		}
	}
	
	bool flag = true;
	
	REP(i,a)
	{
		REP(j,b)
		{
			if(mi[i][j] != mp[i][j])
			{
				flag = false;
				break;
			}
		}
	}
	
	if(!flag)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	else
	{
		cout << "Possible" << endl;
		cout << 202 << ' ' << 10401 << endl;
		
		REP(i,100)
		{
			cout << i+1 << ' ' << i+2 << ' ' << 'X' << endl;
		}
		
		REP(i,100)
		{
			cout << i+102 << ' ' << i+103 << ' ' << 'Y' << endl;
		}
		
		REP(i,101)
		{
			REP(j,101)
			{
				cout << 1+i << ' ' << 202-j << ' ' << dist[i][j] << endl;
			}
		}
		cout << 1 << ' ' << 202 << endl;
		
		/*
		REP(i,a)
		{
			REP(j,b)
			{
				cout << mi[i][j] << endl;
			}
		}
		*/
		
		return 0;
	}
			
	return 0;
}