#include <bits/stdc++.h>
#define ll long long
#define N 100010
#define M 1010

using namespace std;


int read() {
	int s = 0, f = 0; char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return f ? -s : s;
}

int main() {
	int x= read();
	if (x >= 30) puts("Yes");
	else puts("No");
}