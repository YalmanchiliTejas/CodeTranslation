#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int a = 800 * N;
	int b = (N / 15);
	b *= 200;
	printf("%d", a - b);
}
