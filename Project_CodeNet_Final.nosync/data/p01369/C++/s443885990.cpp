#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <queue>
using namespace std;

#define Getsign(n) ((n > 0) - (n < 0))
#define QWERTYR(c) (c == 'y' || c == 'u' || (c >= 'h' && c <= 'p') ?	true : false)
typedef vector<int> Ivec;
typedef pair<int, int> Pos;

int main() {
	char s[33];
	while(scanf("%s",s)){
		if (!strcmp(s, "#"))
			return 0;
		int cou = 0;
		bool QwertyR = QWERTYR(s[0]);
		for (int i = 0; strlen(s) > i; i++) {
			if (QWERTYR(s[i]) != QwertyR) {
				cou++;
				QwertyR = QWERTYR(s[i]);
			}
		}
		printf("%d\n", cou);
	}




	return 0;
}