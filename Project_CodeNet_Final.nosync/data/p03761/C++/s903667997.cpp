#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
char list[110][100];

void work() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		scanf("%s", list[i]);
		sort(list[i], list[i] + strlen(list[i]));
	}
	
	for(int i = 1; i < n; i++) {
		int i1 = 0, i2 = 0;
		int index = 0;
		memset(list[100], 0, sizeof(list[100]));
		while(i1 < strlen(list[0]) && i2 < strlen(list[i])) {
			if(list[0][i1] == list[i][i2]) {
				list[100][index++] = list[0][i1];
				i1++;
				i2++;	
			}
			else if(list[0][i1] > list[i][i2]) {
				i2++;	
			}
			else {
				i1++;	
			}
		}
		memcpy(list[0], list[100], sizeof(list[0]));
	}
	printf("%s\n", list[0]);
}
	
int main() {
	work();
	return 0;
}
	