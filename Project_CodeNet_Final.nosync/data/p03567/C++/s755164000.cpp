#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define lim (int) (1e5+5)
using namespace std;
typedef pair<int,int> ii;
typedef string string;
typedef long long int lli;
string s;
int main()
{
	cin>>s;
	for(int i=0;i<s.length()-1;i++)
	{
		if(s[i]=='A' && s[i+1]=='C')
		{
			printf("Yes");
			return 0;
		}
	}
	printf("No");
}

