#include<map>
#include<queue>
#include<time.h>
#include<limits.h>
#include<cmath>
#include<ostream>
#include<iterator>
#include<set>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define rep_1(i,m,n) for(int i=m;i<=n;i++)
#define mem(st) memset(st,0,sizeof st)
inline int read()
{
	int num=0, w=0;
	char ch=0;
	while (!isdigit(ch))
	{
		w|=ch=='-';
		ch = getchar();
	}
	while (isdigit(ch))
	{
		num = (num<<3) + (num<<1) + (ch^48);
		ch = getchar();
	}
	return w? -num: num;
}
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef pair<double,double> pdd;
const int inf = 0x3f3f3f3f;
const int N=2e6+10;
int a[N];
void solve()
{
	int n;
	cin>>n;
	if(n<30)
	{
		cout<<"No"<<endl;
	}
	else
		cout<<"Yes"<<endl;
}
signed main()
{
	int t=1; 
	while(t--)
		solve();
	return 0;
}

