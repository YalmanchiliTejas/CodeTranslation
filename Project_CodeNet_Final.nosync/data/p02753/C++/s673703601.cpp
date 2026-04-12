#include<iostream>
#include<cstdio>

using namespace std;

char s[3],count_a,count_b;

int main() {
	cin >> s;
	for (int i = 0; i < 3; ++i) {
		if (s[i] == 'A')
			count_a++;
		else
			count_b++;
	}
	if (count_a && count_b)
		printf("Yes");
	else
		printf("No");
	return 0;
}