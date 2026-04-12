#include<bits/stdc++.h>
using namespace std;
#define cs const 
#define int long long
#define mid ((l+r)>>1)
#define low(i) (i&(-i))
#define ls (now<<1)
#define rs (now<<1|1)
cs int ff = 1e6+1;
cs int mod = 1e9+7;
int n, m;
string s;
void init()
{
	cin >> s;
	if( s == "AAA" || s == "BBB" ) puts("No");
	else puts("Yes");
}
signed main()
{
	init();
} 