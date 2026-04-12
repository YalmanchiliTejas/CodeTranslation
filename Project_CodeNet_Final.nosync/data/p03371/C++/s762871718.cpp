#include <bits/stdc++.h>

using namespace std;

int main() {

	int pa,pb,pab, suma, sumb;
	scanf("%d %d %d %d %d", &pa, &pb, &pab, &suma, &sumb);
	int s;
	long long total = 0;
	if(suma > sumb) {
		s = sumb;
	} else {
		s = suma;
	}

	if(2 * pab < pa + pb) {
		total += s * (2 * pab);
		suma -= s;
		sumb -= s;
		if(suma == 0) {
			if(2 * pab < pb) {
				total += sumb * (2 * pab);
				printf("%lld\n", total);
			} else {
				total += sumb * pb;
				printf("%lld\n", total);
			}
		} else {
			if(2 * pab < pa) {
				total += suma * (2 * pab);
				printf("%lld\n", total);
			} else {
				total += suma * pa;
				printf("%lld\n", total);
			}
		}
	} else {
		total += suma * pa;
		total += sumb * pb;
		printf("%lld\n", total);
	}



	return 0;
}