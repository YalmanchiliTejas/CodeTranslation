#include <bits/stdc++.h>
using namespace std;

int main(){
	int s,t;
	scanf("%d%d", &s, &t);
	int p,q,M;
	scanf("%d%d%d", &p, &q, &M);
	int y;
	scanf("%d", &y);
	printf("%d\n", t^s^y);
	return 0;
}
