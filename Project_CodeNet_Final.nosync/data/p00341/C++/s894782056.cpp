#include<bits/stdc++.h>
using namespace std;
int main() {
	int a[12];
	for (int b = 0; b < 12; b++)cin >> a[b];
	sort(a, a + 12);
	if (a[0] == a[3] && a[4] == a[7]&&a[8]==a[11])puts("yes");
	else puts("no");
}