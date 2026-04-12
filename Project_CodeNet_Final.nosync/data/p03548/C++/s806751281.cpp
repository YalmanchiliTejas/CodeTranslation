#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> P;
const int c_INF = 111111111;
const int c_mINF = -111111111;
const int c_YET = -1;
const int c_Dx[4] = { 0,0,1,-1 };
const int c_Dy[4] = { 1,-1,0,0 };
const int c_div = 1000000007; //10^9 + 7


ll R[399];

int main() {

	int X,Y,Z;
	scanf("%d%d%d", &X,&Y,&Z);

	int ans;

	for (int i = 0; i < 100000; i++) {
		if (X - Y*i >=  Z * (i + 1)) {
			ans = i;
		}
		else {
			break;
		}
	}

	printf("%d", ans);


}


void  bubbleSort(char number[]) {
	for (int i = 0; i < strlen(number); i++)
		for (int j = i + 1; j < strlen(number); j++)
			if ((int)number[i] > (int)number[j]) {
				char tmp = number[i];
				number[i] = number[j];
				number[j] = tmp;
			}
}