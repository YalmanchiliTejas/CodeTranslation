#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define int long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
void lala()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int powr(int x,int y,int z)
{
	int	ans=1;
	int square=x;
	if(y==0)
	    return 1;
	while(y!=0)
	{
	    if(y%2)
	        ans=ans*square;
	    square=(square*square)%z;
	    y=y/2;
	    if(ans>z)
	        ans=ans%z;
	}
	return ans;
}

int32_t main()
{
std::ios::sync_with_stdio(false);


int n;
cin >> n;
int a[n];
for (int i = 0; i < n; i++)
cin >> a[i];

int res = 0;
int sum = 0;
for (int i = 0; i < n; i++)
sum = (sum + a[i] + mod) % mod;

for (int i = n - 1; i >= 0; i--)
{
sum = (sum - a[i]) % mod;
res = (res + (a[i] * sum) % mod + mod) % mod;

}
cout << (res + mod) % mod << endl;
return 0;
}


