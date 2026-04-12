#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define EQ(a,b) (abs((a)-(b))<EPS)
int player[1001];
vector<string> p;
int n,m;
int now=0;
int res;
int stoi(string s)
{
	int t;
	istringstream is(s);
	is >> t;
	return t;
}
int next()
{
	int a=-1;
	for(int i=now+1;;i++)
	{
		if(player[i%n]==0)
		{
			a=i%n;
			break;
		}
	}
	return a;
}
int main()
{
	while(1)
	{
		p.clear();
		memset(player,0,sizeof(player));
		now=0;
		cin >> n >> m;
		if(n==0&&m==0)break;
		res=n;
		for(int i=0;i<m;i++)
		{
			string s;
			cin >> s;
			p.pb(s);
		}
		for(int i=0;i<m;i++)
		{
			if((i+1)%3==0&&(i+1)%5==0)
			{
				if(p[i]!="FizzBuzz")
				{
					player[now]=1;
					res--;
				}
			}
			else if((i+1)%3==0&&(i+1)%5!=0)
			{
				if(p[i]!="Fizz")
				{
					player[now]=1;
					res--;
				}
			}
			else if((i+1)%5==0&&(i+1)%3!=0)
			{
				if(p[i]!="Buzz")
				{
					player[now]=1;
					res--;
				}
			}
			else
			{
				if((i+1)!=stoi(p[i]))
				{
					player[now]=1;
					res--;
				}
			}
			if(res==1)break;
			now=next();
		}
		bool k=true;
		for(int i=0;i<n;i++)
		{
			if(player[i]==0)
			{
				if(k)
				{
					cout << i+1;
					k=false;
				}
				else
				{
					cout << ' ' << i+1;
				}
			}
		}
		cout << endl;
	}
	return 0;
}