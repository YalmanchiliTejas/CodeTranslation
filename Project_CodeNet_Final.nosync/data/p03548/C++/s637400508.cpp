#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
int X, Y, Z;

int main(void){
	//IO("test.in", "test.out");
	scanf("%d%d%d", &X, &Y, &Z);
	printf("%d\n", (X - Z) / (Y + Z));
}