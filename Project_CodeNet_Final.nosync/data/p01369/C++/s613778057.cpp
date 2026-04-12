#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
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
#define EQ(a,b) (abs((a)-(b))<eps)
int a[27];
int main()
{
	a['q'-'a']=1;
	a['w'-'a']=1;
	a['e'-'a']=1;
	a['r'-'a']=1;
	a['t'-'a']=1;
	a['a'-'a']=1;
	a['s'-'a']=1;
	a['d'-'a']=1;
	a['f'-'a']=1;
	a['g'-'a']=1;
	a['z'-'a']=1;
	a['x'-'a']=1;
	a['c'-'a']=1;
	a['v'-'a']=1;
	a['b'-'a']=1;
	string s;
	while(1)
	{
		cin >> s;
		if(s=="#")break;
		int ans=0;
		for(int i=1;i<s.size();i++)
		{
			if(a[s[i]-'a']!=a[s[i-1]-'a'])ans++;
		}
		cout << ans << endl;
	}
	return 0;
}