#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<iterator>
#include<cmath>
#include<string>
#include<algorithm>
#include<sstream>
#include<queue>
#include<list>
#include<deque>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<chrono>


/*  auto start = high_resolution_clock::now();
auto stop = high_resolution_clock::now();
auto duration = duration_cast<milliseconds>(stop - start);
pr(duration.count());    */


#define FastIO      ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define pb          push_back
#define siz         100009
#define mp          make_pair
#define ll          long long int
#define fileout     freopen("output.txt","w",stdout)
#define filein      freopen("input.txt","r",stdin)
#define pi          acos(-1.0)
#define all(x)      x.begin(),x.end()
#define ull		    unsigned long long int
#define m(a)	    memset(a,0,sizeof(a))
#define f(i,n)	    for(ll i=0;i<n;i++)
#define sc(a)	    scanf("%lld",&a)
#define pr(a)	    printf("%lld\n",a)
const ll inf = 5000000000000000;
ll in = 1000000000000000000;
using namespace std;

int main()
{
	FastIO;
	ll a,b,c,d, co, t, i, j, k, n,m,r;
	string s('.',150),tmp[150];
	char ans[150][150];
	cin >> r >> c;
	k = 0;
	f(i, r)
	{
		cin >> s;
		f(j, s.size())
		{
			if (s[j] == '#')
			{
				tmp[k] = s;
				k++;
				break;
			}
		}
	}
	co = 0;
	n = 0;
	f(i, c)
	{
		f(j, k)
		{
			if (tmp[j][i] == '#')
			{
				co++;
				for (d = 0; d < k; d++)
				{
					ans[d][n] = tmp[d][i];
				}
				n++;
				break;
			}
		}
	}
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < co; j++)
		{
			cout << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}