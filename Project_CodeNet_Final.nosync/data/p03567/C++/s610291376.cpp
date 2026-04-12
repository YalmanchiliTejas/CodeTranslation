#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <string>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char str[10];

int main()
{
	scanf("%s",&str);
	int n=strlen(str);
	for(int i=0;i+1<n;i++)
	{
		if(str[i]=='A'&&str[i+1]=='C')
		{
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}
