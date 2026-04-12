// Dont hack this or I hack ur mama
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#define ll long long 
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
using namespace std;

////////////// END OF TEMPLATE
const int nmax = 0;
int n;
int a[200100];
void read()
{
	cin >> n;
	for(int i = 0 ; i < n; ++i)
		cin >> a[i];

}
void solve()
{
	int i = n-1;
	while( i >= 0)
	{
		cout << a[i] << ' ';
		i-=2;
	}
	if( i == -1)
		i = 0;
	else if(i == -2)
		i = 1;
	while( i < n)
	{	cout << a[i] << ' ';
		i+=2;
	}
	cout << endl;
}
int main()
{
	std::ios::sync_with_stdio(false);
	read();
	solve();
	return 0;
}
