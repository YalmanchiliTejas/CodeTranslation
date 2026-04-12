#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long LL;
const int inf = 1 << 30;

char s[10];
int main()
{
	while(scanf("%s", s + 1) != EOF)
	{
		int len = strlen(s + 1);
		bool f = 0;
		for(int i = 1; i < len; i++) {
			if(s[i] == 'A' && s[i + 1] == 'C')
				f = 1;
		}
		if(f == 1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}