#include <stdio.h>
#include <algorithm>

#define lli long long int

using namespace std;

int main() {
	lli banyak, angka[100010], ans = 0, temp = 0;
	scanf("%lld", &banyak);
	for (lli i = 0; i < banyak; i++)
		scanf("%lld", &angka[i]);
	sort(angka, angka + banyak);
	if (banyak % 2 < 1) {
		for (lli i = 0; i < ((banyak / 2) - 1); i++)
			ans -= (2 * angka[i]);
		ans += (angka[banyak / 2] - angka[(banyak / 2) - 1]);
		for (lli i = ((banyak / 2) + 1); i < banyak; i++)
			ans += (2 * angka[i]);
	}
	else {
		for (lli i = 0; i < (banyak / 2) - 1; i++)
			ans -= (2 * angka[i]);
		ans -= (angka[banyak / 2] + angka[(banyak / 2) - 1]);
		for (lli i = ((banyak / 2) + 1); i < banyak; i++)
			ans += (2 * angka[i]);
		for (lli i = 0; i < (banyak / 2); i++)
			temp -= (2 * angka[i]);
		temp += (angka[banyak / 2] + angka[(banyak / 2) + 1]);
		for (lli i = (banyak / 2) + 2; i < banyak; i++)
			temp += (2 * angka[i]);
		ans = max(ans, temp);
	}
	printf("%lld\n", ans);
	return 0;
}