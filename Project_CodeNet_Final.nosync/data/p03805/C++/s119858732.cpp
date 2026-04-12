#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<functional>
#include<queue>
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

using namespace std;

typedef long long ll;
typedef vector<int> iv;
typedef vector<iv> iiv;
typedef vector<string> sv;

int main()
{
	int n,m,ans = 0;
	cin >> n >> m;
	
	vector<vector<int> > v(n);
	
	REP(i,m)
	{
		int a,b;
		cin >> a >> b;
		v[a-1].PB(b-1);
		v[b-1].PB(a-1);
	}
	
	vector<int> node;
	REP(i,n-1)node.PB(i+1);
	
	do
	{
		bool flag = true;
		int now = 0;
		REP(i,n-1)
		{
			if(find(ALL(v[now]),node[i]) == v[now].end())
			{
				flag = false;
				break;
			}
			now = node[i];
		}
		if(flag)ans++;
	}while(next_permutation(ALL(node)));
	
	cout << ans << endl;
	
	return 0;
}