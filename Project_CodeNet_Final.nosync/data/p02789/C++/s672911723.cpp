#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>

using namespace std;
typedef long long ll;

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	
	if(N == M){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	
	return 0;
}