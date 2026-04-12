#include <stdio.h>
#include <algorithm>
using namespace std;
using ll = long long;

int n, m;
int main() {
	scanf("%d %d", &n, &m);
	printf(n <= m ? "Yes\n" : "No\n");
}