#include <cstdio>
#include <cstring>
const int maxn = 10;
char s[maxn];
int main()
{
	scanf("%s", &s);
	int len = strlen(s);
	bool flag = false;
	for(int i = 0; i < len - 1; ++i)
		if(s[i] == 'A' && s[i + 1] == 'C')
		{
			flag = true; break;
		}
	puts(flag ? "Yes" : "No");
	return 0;
}