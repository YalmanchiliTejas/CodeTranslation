#include<cstdio>
#include<algorithm>
#include<climits>
using namespace std;
static const int MAX_P = 100000;

int p;
int num[MAX_P];
int memo[MAX_P];

int main(){
	scanf("%d", &p);
	for(int j = 0; j < p; j++){
		scanf("%d", &num[j]);
	}
	reverse(num, num + p);
	fill(memo, memo + p, INT_MAX);
	int res = 0;
	for(int j = 0; j < p; j++){
		*upper_bound(memo, memo + p, num[j]) = num[j];
	}
	printf("%d\n", lower_bound(memo, memo + p, INT_MAX) - memo);
	return 0;
}
