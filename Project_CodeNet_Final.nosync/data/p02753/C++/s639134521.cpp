#include<bits/stdc++.h>
#include<bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int mod = 998244353;

char s[maxn];
set<char> ss;

int main()
{
	scanf("%s",s);
	for(int i=0;i<3;i++)
		ss.insert(s[i]);
	printf("%s\n",ss.size()==2?"Yes":"No");
	return 0;
}


