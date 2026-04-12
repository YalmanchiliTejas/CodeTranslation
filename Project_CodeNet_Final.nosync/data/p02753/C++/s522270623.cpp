/*
	Name:
	Author: xiaruize
	Date:
*/

#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define MOD 1000000007
#define ALL(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long
#define form(i,j,n) for(int i=int(j);i<=int(n);i++)
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define pis pair<int,string>
#define sec second

inline int read()
{
    char ch=getchar();
    int x=0,f=1;
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
    return x*f;
}

int main()
{
 	ios::sync_with_stdio(false);
	cin.tie(0);
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	string s;
	cin>>s;
	bool a=false,b=false;
	for(int i=0;i<3;i++)
	{
		if(s[i]=='A')
		{
			a=true;
		}
		else if(s[i]=='B')
		{
			b=true;
		}
	}
	if(a&&b)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}