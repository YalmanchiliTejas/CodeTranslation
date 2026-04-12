#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<LD, LD> PLDLD;
typedef vector<int> VI;
typedef vector<char> VB;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define ALL(a) a.begin(),a.end()

const double eps=1e-5;
const long long INF=(LL)(1e9)*(LL)(1e9);

template<class T>
void chmin(T& a, const T& b)
{
	if(a>b)
		a=b;
}
template<class T>
void chmax(T& a, const T& b)
{
	if(a<b)
		a=b;
}

const LL pow(const LL p, const LL q)
{
	LL t=1;
	REP(i,q)
		t*=p;
	return t;
}



int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin>>s;
	REP(i,s.size()-1)
	{
		if(s[i]=='A' && s[i+1]=='C')
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	

	
}