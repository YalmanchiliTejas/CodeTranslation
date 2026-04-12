#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

pair<int, int> A[200200];
int R[200200];
void proc()
{
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i].first), A[i].second = i;
	sort(A, A + N);

	for (int i = 0; i < N; i++) {
		if (i < N / 2) R[A[i].second] = A[N / 2].first;
		else R[A[i].second] = A[N / 2 - 1].first;
	}
	for (int i = 0; i < N; i++) printf("%d\n", R[i]);
}

int main()
{
#ifdef __LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	proc();
	return 0;
}