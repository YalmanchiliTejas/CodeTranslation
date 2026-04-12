#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define N_MAX 100001

void solv()
{
	int N; scanf("%d", &N);
	int s[N_MAX]; 
	for (int i = 0; i < N; i++){
		scanf("%d", s + i);
	}

	long long int ret = 0;
	for (int i = 1; i < N; i++){
		long long int suml = 0, sumr = 0;
		for (int j = 1; j < N; j++){
			if (i*j >= N || (N - 1 - i*j) < 0) {
				break;
			}
			if (i*j == (N - 1 - i*j)){
				break;
			}
			if (i*(j + 1) == (N - 1 - i*j)){
				suml += s[i*j];
				sumr += s[N - 1 - i*j];
				ret = max(ret, suml + sumr);
				break;
			}
			if ((N - 1 - i*j) < i){
				break;
			}
			suml += s[i*j];
			sumr += s[N - 1 - i*j];
			ret = max(ret, suml + sumr);
		}
	}

	printf("%lld", ret);

	return;
}

int main()
{
	FILE *fin = NULL, *fout = NULL;
	//fin = freopen("input.txt", "r", stdin);
	//fout = freopen("output.txt", "w", stdout);

	solv();

	//finalize
	if (NULL != fin) fclose(fin);
	if (NULL != fout) fclose(fout);

	return 0;
}