#include<cstdio>
using namespace std;

int a, b;
char ch;

int main()
{
	for (int i = 1; i <= 3; i++) {
		ch = getchar();
		if (ch == 'A') a++;
		else b++;
	}
	if (a > 0 && b > 0) printf("Yes");
	else printf("No");
	return 0;
}