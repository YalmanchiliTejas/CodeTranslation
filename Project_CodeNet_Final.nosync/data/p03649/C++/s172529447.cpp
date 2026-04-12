#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

#define st first
#define nd second
#define make(a,b) make_pair(a,b)

typedef pair<int,int> pun;
typedef long long ll;

long long tab[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf("%lld", tab + i);
	}
	long long wynik = 0;
	while (true) {
		long long ile = 0;
		long long wklad = 0;
		for (int i = 0; i < n; i ++) {
			wklad = tab[i] / n;
			tab[i] %= n;
			tab[i] -= wklad;
			ile += wklad;
		}
		wynik += ile;
		if (ile == 0) {
			break;
		}
		for (int i = 0; i < n; i ++) {
			tab[i] += ile;
		}
	}
	printf("%lld\n", wynik);
}
