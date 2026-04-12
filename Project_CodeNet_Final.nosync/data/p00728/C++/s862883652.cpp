#include <iostream>
#include <cstdio>	
#include <cstring>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

const int MAX_S = -1;
const int MIN_S = 1001;
int score[1001];

int main()
{
	int n, m;
	while (scanf ("%d", &n ) && n ){
		memset (score, 0, sizeof (score ) );
		int max_s = MAX_S;
		int min_s = MIN_S;
		rep (i, n ){
			int in;
			scanf (" %d", &in );
			score[in]++;
			max_s = max (max_s, in );
			min_s = min (min_s, in );
		} // end rep
		score[max_s]--;
		score[min_s]--;
		int sum = 0;
		int sum_n = 0;
		for (int i = 0; i <= 1000; i++ ){
			sum += i*score[i];
			sum_n += score[i];
		} // end for
		int res = sum/sum_n;
		printf ("%d\n", res );
	} // end loop
		
	return 0;
}