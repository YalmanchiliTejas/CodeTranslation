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
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
struct Team
{
	string team;
	int num,point;
};
bool comp(Team a,Team b)
{
	if(a.point!=b.point)return a.point>b.point;
	return a.num < b.num;
}
int main()
{
	bool first=true;
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)break;
		if(!first) cout << endl;
		else first=false;
		vector<Team> vec;
		for(int i=0;i<n;i++)
		{
			string team;
			int win,lose,tie;
			cin >> team >> win >> lose >> tie;
			int point=win*3+tie;
			Team a;
			a.team=team;
			a.num=i;
			a.point=point;
			vec.pb(a);
		}
		sort(vec.begin(),vec.end(),comp);
		for(int i=0;i<vec.size();i++)
		{
			cout << vec[i].team << ',' << vec[i].point << endl;
		}
	}
	return 0;
}