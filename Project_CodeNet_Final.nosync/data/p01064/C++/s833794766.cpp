#define _USE_MATH_DEFINES

#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

vector<int> tf;

int N, a, d, M, K;
int data[200000][3];

int main(){
	scanf("%d%d%d%d", &N, &a, &d, &M);
	for (int i = 0; i < M; ++i) {
		scanf("%d%d%d", &data[i][0], &data[i][1], &data[i][2]);
	}
	scanf("%d", &K);
	
	int cur = K;
	for (int i = M - 1; i >= 0; --i) {
		if (data[i][1] <= cur && cur <= data[i][2]) {
			if (data[i][0] == 0) {
				cur = data[i][2] - (cur - data[i][1]);;
			}
			tf.push_back(data[i][0]);
		}
	}
	
	int value = a + (cur - 1) * d;
	for (int i = tf.size() - 1; i >= 0; --i) {
		if (tf[i] == 0) {
		}
		else if (tf[i] == 1) {
			value++;
		}
		else if (tf[i] == 2) {
			value >>= 1;
		}
	}
	printf("%d\n", value);

	return 0;
}