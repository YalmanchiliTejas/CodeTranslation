#include <bits/stdc++.h>

#define LL long long
#define COIN const int
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REPD(i,n) for((i)=(n)-1;(i)>=0;(i)--)

#define ALL(c) (c).begin(), (c).end()
#define LEN(s) (s).size()
#define CLEAR(x) memset(x,0,sizeof x);

#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define VI vector<int>
#define VS vector<string>
#define VII vector<PII>
#define VVI vector<VI>

#define PIII 3.1415926
#define PI 3.14
/*****************************************************************************/

using namespace std;

string s;
int a,b,i;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >>s;
	REP(i,s.size())
	{
		if (s[i]=='A') a++;
		else b++;
	}
	if (a==0 || b==0)
		cout <<"No"<<endl;
	else
		cout <<"Yes"<<endl;
	return 0;
}
/******************************************************************************
******************************************************************************/
