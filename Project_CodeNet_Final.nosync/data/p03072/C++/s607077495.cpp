/******************************\
*  Everyone has a different way of thinking, so God Created us
Hope You Respect My Way..,Thank You ):  *
*                            *
*   Created by : Murad   *
\******************************/
//std::transform(s1.begin(), s1.end(), s1.begin(),::tolower);
#include<iostream>
using namespace std;
#include<string>
#include<sstream>
#include<algorithm>
#include<functional>
#include<set>
#include<math.h>
#include<map>
#include<vector>
#include<list>
#define pi 3.1415926536
#define forn(i,a,b)for(int i=a;i<b;i++)
#define LL long long
#define MP make_pair
#define fi first
#define se second
#define INF 2147483647
#define _INF -2147483647
#define pq priority_queue
#define MM multimap
#define PB push_back
#define ipair pair<int,int>
#define lpair pair<LL,LL>
#define MAXN 100004
#define El3zba ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define modd 1000000007
LL MMIN(LL a, LL b)
{
	if (a <= b)
		return a;
	else
		return b;
}
LL MMAX(LL a, LL b) {
	if (a >= b)
		return a;
	else
		return b;
}
int main()
{
	int n,ans=1;
	cin >> n;
	vector<int>a(n);
	forn(i, 0, n)cin >> a[i];
	int ma = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] >= ma)ans++, ma = a[i];
	}
	cout << ans << endl;
	return 0;
}