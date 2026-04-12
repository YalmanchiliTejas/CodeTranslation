#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
int main()
{
	string s;
	cin>>s;
	if(s[0]==s[1]&&s[1]==s[2])printf("No\n");
	else printf("Yes\n");
	return 0;
}