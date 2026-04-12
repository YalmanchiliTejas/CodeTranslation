#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define INF         1e9
#define EPS         1e-9
#define REP(i,n)    for(lint i=0,i##_len=(n);i<i##_len;++i)
#define REP1(i,n)   for(lint i=1,i##_len=(n);i<=i##_len;++i)
#define REPR(i,n)   for(lint i=(n)-1;i>=0;--i)
#define REPR1(i,n)  for(lint i=(n);i>0;--i)
#define REPC(i,obj) for(auto i:obj)
#define R_UP(a,b)   (((a)+(b)-1)/(b))
#define ALL(obj)    (obj).begin(),(obj).end()
#define SETP        cout << fixed << setprecision(8)
using namespace std;
using lint = long long;
template<typename T = lint>inline T in() { T x; cin >> x; return x; }

signed main()
{
	int h = in(), w = in();
	bool *is_white_row = new bool[h], *is_white_col = new bool[w];
	REP(i, h)is_white_row[i] = true;
	REP(i, w)is_white_col[i] = true;
	vector<vector<char>>bw(h, vector<char>(w));
	REP(i, h)
	{
		string s = in<string>();
		REP(j, w)
		{
			bw[i][j] = s[j];
			is_white_row[i] &= (bw[i][j] == '.');
			is_white_col[j] &= (bw[i][j] == '.');
		}
	}
	REP(i, h)
	{
		REP(j, w)if (!is_white_row[i] && !is_white_col[j])cout << bw[i][j];
		if (!is_white_row[i])cout << endl;
	}
}