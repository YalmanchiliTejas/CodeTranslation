#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iomanip>
#include <vector>
#include <cstdio>
#include <float.h>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <stack>
#include <functional>
 
using namespace std;
 
#define endl '\n'
#define MOD 1000000007
#define INF 1ll<<30
#define MAX 100010
#define eps 1e-11
#define bit_max 1ll<<32
#define _USE_MATH_DEFINES




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   	//freopen("input.txt","r",stdin);
//   	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	int b[n],c[n];
	long long int ans = -1;
	if(n%2!=0)
	{
		b[0] = 1;
		b[n-1] = 1;
		bool mins = true;
		for(int i=1;i<n-1;i++)
		{
			b[i] = 2;
			if(mins)
			{
				b[i]*=-1;
			}
			mins = !mins;
		}
		for(int i=0;i<n;i++)
		{
			c[i] = -1*b[i];
		}
		sort(b,b+n);
		sort(c,c+n);
		long long int temp=0,temper =0;
		for(int i=0;i<n;i++)
		{
			temp+= (a[i]*b[i]);
			temper+=(a[i]*c[i]);
		}
		ans = max(temp,temper);
	}
	else
	{

		b[0] = 1;
		b[n-1] = -1;
		bool mins = true;
		for(int i=1;i<n-1;i++)
		{
			b[i] = 2;
			if(mins)
			{
				b[i]*=-1;
			}
			mins = !mins;
		}
		for(int i=0;i<n;i++)
		{
			c[i] = -1*b[i];
		}
		sort(b,b+n);
		sort(c,c+n);
		long long int temp=0,temper =0;
		for(int i=0;i<n;i++)
		{
			temp+= a[i]*b[i];
			temper+=a[i]*c[i];
		}
		ans = max(temp,temper);
	}
	cout<<ans;

	return 0 ;
}
