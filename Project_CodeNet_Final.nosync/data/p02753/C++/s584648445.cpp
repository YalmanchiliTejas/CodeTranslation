#include<bits/stdc++.h>
#define FOR(i,a,b)for(int i=(a),_b=(b);i<=_b;i++)
#define FORN(i,b,a)for(int i=(b);_a=(a);i>=_a;i--)
#define REP(i,n)for(int i=0,_n=n;i<n;i++)
#define ll long long
#define pii pair<int,int>
#define re return
#define vi vector<int>
#define pb push_back
#define si set<int>
#define in insert
#define fl float
#define db double
#define ld long double
#define X first
#define Y second
#define st string
#define ull unsigned long long
#define mod 1000000007
#define INF 1000000007
#define x1 XZVJDFADSPFOE
#define y1 GASDIJSLDAEJF
#define x2 DFDAJKVOHKWIW
#define y2 PSFSAODSXVNMQ
using namespace std;
inline void read(int &x)
{
	short negative=1;
    x=0;
    char c=getchar();
    while(c<'0' || c>'9')
    {
		if(c=='-')
			negative=-1;
		c=getchar();
	}
    while(c>='0' && c<='9')
        x=(x<<3)+(x<<1)+(c^48),c=getchar();
    x*=negative;
}
int main()
{
	string s;
	cin>>s;
	bool a=0,b=0;
	REP(i,s.size())
	{
		if(s[i]=='A')a=1;
		if(s[i]=='B')b=1;
	}
	if(a&&b)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}

