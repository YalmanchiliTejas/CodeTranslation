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

using namespace std;

typedef long long ll;
typedef vector<int> iv;
typedef vector<iv> iiv;
typedef vector<string> sv;

int ch[30];
int hi[30];

int main()
{
	int n;cin >> n;
	
	string str;cin >> str;
	REP(i,str.size())
	{
		ch[str[i]-'a']++;
	}
	
//	SHOW1d(ch,26);
	
	REP(i,n-1)
	{
		REP(j,30)hi[j] = 0;
		cin >> str;
		REP(j,str.size())
		{
			hi[str[j]-'a']++;
		}
		REP(j,30)
		{
			ch[j] = min(ch[j],hi[j]);
		}
//		SHOW1d(ch,26);
	}
	
	REP(i,26)
	{
		REP(j,ch[i])
		{
			char tmp = 'a' + i;
			cout << tmp;
		}
	}
	cout << endl;
		

	return 0;
}