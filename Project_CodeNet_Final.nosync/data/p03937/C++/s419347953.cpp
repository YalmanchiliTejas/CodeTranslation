#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

char s[10][10];
int main() {
	int h, w; scanf("%d%d", &h, &w);
	rep(i, h)scanf("%s", s[i]);
	puts(count(s[0], s[10], '#') == h + w - 1 ? "Possible" : "Impossible");
}