#include <iostream>
#include <cstdio>
#include <cstdlib>
#define N 100005
using namespace std;

int n;
string t;
bool a[N], b[N];

void g() {
	int i;
	for (i = 0; i < n; i++) printf("%c", b[i] ? 'W' : 'S');
	exit(0);
}

void f() {
	int i;
	for (i = 2; i <= n + 1; i++) b[i] = b[i - 2] ^ b[i - 1] ^ a[i - 1];
	if (b[0] == b[n] && b[1] == b[n + 1]) g();
}

int main()
{
	int i;
	cin >> n >> t;
	for (i = 0; i < t.size(); i++) a[i] = (t[i] == 'x');
	a[n] = a[0];
	b[0] = 0; b[1] = 0; f();
	b[0] = 0; b[1] = 1; f();
	b[0] = 1; b[1] = 0; f();
	b[0] = 1; b[1] = 1; f();
    cout << "-1" << endl;
    return 0;
}